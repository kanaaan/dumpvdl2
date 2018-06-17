/*
 *  dumpvdl2 - a VDL Mode 2 message decoder and protocol analyzer
 *
 *  Copyright (c) 2017 Tomasz Lemiech <szpajder@gmail.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#define _POSIX_C_SOURCE 201112L	/* getaddrinfo */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "dumpvdl2.h"
// UDP client header
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

FILE *outf;
int pp_sockfd = 0;
uint8_t hourly = 0, daily = 0, utc = 0, output_raw_frames = 0, dump_asn1 = 0, output_raw_frames_only = 0;
//UDP broadcast
int sockfd_udp = -1;
struct sockaddr_in     udp_servaddr;
//UDP broadcast //

static char *filename_prefix = NULL;
static char *extension = NULL;
static size_t prefix_len;
static struct tm current_tm;

static int open_outfile() {
	char *filename = NULL;
	char *fmt = NULL;
	size_t tlen = 0;

	if(hourly || daily) {
		time_t t = time(NULL);
		if(utc)
			gmtime_r(&t, &current_tm);
		else
			localtime_r(&t, &current_tm);
		char suffix[16];
		if(hourly)
			fmt = "_%Y%m%d_%H";
		else	// daily
			fmt = "_%Y%m%d";
		tlen = strftime(suffix, sizeof(suffix), fmt, &current_tm);
		if(tlen == 0) {
			fprintf(stderr, "open_outfile(): strfime returned 0\n");
			return -1;
		}
		filename = XCALLOC(prefix_len + tlen + 2, sizeof(uint8_t));
		sprintf(filename, "%s%s%s", filename_prefix, suffix, extension);
	} else {
		filename = filename_prefix;
	}

	if((outf = fopen(filename, "a+")) == NULL) {
		fprintf(stderr, "Could not open output file %s: %s\n", filename, strerror(errno));
		return -1;
	}
	XFREE(filename);

	return 0;
}

int init_output_file(char *file) {
	if(!strcmp(file, "-")) {
		outf = stdout;
	} else {
		filename_prefix = file;
		prefix_len = strlen(filename_prefix);
		if(hourly || daily) {
			char *ext = strrchr(filename_prefix, '.');
			if(ext != NULL && (ext == filename_prefix || ext[1] == '\0'))
				ext = NULL;
			if(ext) {
				extension = strdup(ext);
				*ext = '\0';
			} else {
				extension = strdup("");
			}
		}
		return open_outfile();
	}
	return 0;
}

int init_pp(char *pp_addr) {
	if(pp_addr == NULL) return -1;

	char *addr, *port;
	if((addr = strtok(pp_addr, ":")) == NULL)
		return -1;
	if((port = strtok(NULL, ":")) == NULL)
		return -1;

	struct addrinfo hints, *result, *rptr;
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_flags = 0;
	hints.ai_protocol = 0;
	int ret = getaddrinfo(addr, port, &hints, &result);
	if(ret != 0) {
		fprintf(stderr, "Could not resolve %s: %s\n", pp_addr, gai_strerror(ret));
		return -1;
	}
	for (rptr = result; rptr != NULL; rptr = rptr->ai_next) {
		pp_sockfd = socket(rptr->ai_family, rptr->ai_socktype, rptr->ai_protocol);
		if (pp_sockfd == -1) continue;
		if (connect(pp_sockfd, rptr->ai_addr, rptr->ai_addrlen) != -1) break;
		close(pp_sockfd);
		pp_sockfd = 0;
	}
	if (rptr == NULL) {
		fprintf(stderr, "Could not connect to Planeplotter: all addresses failed\n");
		pp_sockfd = 0;
		return -1;
	}
	freeaddrinfo(result);
	return 0;
}

int init_udp(int udp_port)
{
	memset(&udp_servaddr, 0, sizeof(udp_servaddr));
	// Filling server information
	udp_servaddr.sin_family = AF_INET;
	udp_servaddr.sin_port = htons(udp_port);
	udp_servaddr.sin_addr.s_addr = INADDR_ANY;

	if ((sockfd_udp = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		fprintf(stderr, "socket creation failed");
		return -1;
	}
	printf(GREEN "udp socket initialized, send frames to localhost:%d", udp_port);
	printf(RESET"\n");
	return 0;
}
int send_udp(time_t t,uint32_t freq,char is_valid,uint32_t datalen,void *data)
{
	static unsigned char udp_buff[4048];
	static uint64_t seq=0; 
	unsigned char *ptr_udp_buff=udp_buff;
	uint32_t udp_len=0;
	//Sequence number
	seq++;
	memcpy(ptr_udp_buff,(void *)&seq,sizeof(uint64_t));
	ptr_udp_buff+=sizeof(uint64_t);
	udp_len+=sizeof(uint64_t);
	//frequency
	memcpy(ptr_udp_buff,(void *)&freq,sizeof(uint32_t));
	ptr_udp_buff+=sizeof(uint32_t);
	udp_len+=sizeof(uint32_t);
	//is_valid
	memcpy(ptr_udp_buff,(void *)&is_valid,sizeof(char));
	ptr_udp_buff+=sizeof(char);
	udp_len+=sizeof(char);
	//time
	memcpy(ptr_udp_buff,(void *)&t,sizeof(time_t));
	ptr_udp_buff+=sizeof(time_t);
	udp_len+=sizeof(time_t);
	//Length
	memcpy(ptr_udp_buff,(void *)&datalen,sizeof(uint32_t));
	ptr_udp_buff+=sizeof(uint32_t);
	udp_len+=sizeof(uint32_t);
	//data
	memcpy(ptr_udp_buff,(void *)data,datalen);
	ptr_udp_buff+=datalen;
	udp_len+=datalen;
	
	sendto(sockfd_udp, (const char *)udp_buff, udp_len,
		0, (const struct sockaddr *) &udp_servaddr,
		sizeof(udp_servaddr));
	
	return 0;
}

int rotate_outfile() {
	struct tm new_tm;
	time_t t = time(NULL);
	if(utc)
		gmtime_r(&t, &new_tm);
	else
		localtime_r(&t, &new_tm);
	if((hourly && new_tm.tm_hour != current_tm.tm_hour) || (daily && new_tm.tm_mday != current_tm.tm_mday)) {
		fclose(outf);
		return open_outfile();
	}
	return 0;
}

void output_raw(uint8_t *buf, uint32_t len) {
	if(len == 0)
		return;
	fprintf(outf, "   ");
	for(int i = 0; i < len; i++)
		fprintf(outf, "%02x ", buf[i]);
	fprintf(outf, "\n");
}

void output_raw_udp(uint8_t *buf, uint32_t len) {
	if (len == 0)
		return;
	printf("  ");
	for (int i = 0; i < len; i++)
		printf("%02x ", buf[i]);
	printf("\n");
}

