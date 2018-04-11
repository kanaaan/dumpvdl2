/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "FANSACTwoWayDataLinkCommunications"
 * 	found in "fans-cpdlc.asn1"
 * 	`asn1c -fcompound-names -gen-PER`
 */

#ifndef	_FANSTimePosition_H_
#define	_FANSTimePosition_H_


#include <asn_application.h>

/* Including external dependencies */
#include "FANSTime.h"
#include "FANSPosition.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* FANSTimePosition */
typedef struct FANSTimePosition {
	FANSTime_t	 time;
	FANSPosition_t	 position;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} FANSTimePosition_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_FANSTimePosition;

#ifdef __cplusplus
}
#endif

#endif	/* _FANSTimePosition_H_ */
#include <asn_internal.h>
