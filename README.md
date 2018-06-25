# dumpvdl2

dumpvdl2 is a VDL Mode 2 message decoder and protocol analyzer (fork from [dumpvdl2](https://github.com/szpajder/dumpvdl2)).
This fork transforms the dumpvdl2 to a UDP generator for AVLC Frames

### Added Features

- Add two new options --raw-frames-udp and --udp-port to enable broadcasting AVLC frames as raw bytes to UDP localhost:udp-port; default udp-port value is 8080

- Output Raw AVLC to console with coloring : Green coloring if the AVLC checksum is valid and Red if invalid

### Example 

```
./dumpvdl2 --gain 40 --correction 0 --rtlsdr 0 --raw-frames-udp --utc --udp-port 8090
```

![dumpvdl2 screenshot](putty-console.png?raw=true)


Generated UDP frames can be verified under Linux using the tcpdump tool or using the python script [avlc-udp.py](https://github.com/kanaaan/dumpvdl2/blob/master/avlc-udp.py)

```
tcpdump -vx  -i lo udp port 8090

```

```
python avlc-udp.py

```
### RTLSDR testing, compilation under Linux raspberrypi 4.14.34-v7+

```
sudo apt-get install librtlsdr-dev
git clone https://github.com/kanaaan/dumpvdl2
cd dumpvdl2
make
```


### SDRplay-RSPduo testing, compilation under Linux raspberrypi 4.14.34-v7+

Install [driver](https://www.sdrplay.com/downloads) from (Raspberry Pi section) and execute the SDRplay_RSP_API-RPi-2.13.1.run script (chmod +x required)
```
git clone https://github.com/kanaaan/dumpvdl2
cd dumpvdl2
make WITH_SDRPLAY=1 WITH_RTLSDR=0
dumpvdl2 --sdrplay 0  --antenna A --biast 0 --notch-filter 1 136725000 136975000 136875000
```
