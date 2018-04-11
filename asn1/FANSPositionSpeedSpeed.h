/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "FANSACTwoWayDataLinkCommunications"
 * 	found in "fans-cpdlc.asn1"
 * 	`asn1c -fcompound-names -gen-PER`
 */

#ifndef	_FANSPositionSpeedSpeed_H_
#define	_FANSPositionSpeedSpeed_H_


#include <asn_application.h>

/* Including external dependencies */
#include "FANSPosition.h"
#include "FANSSpeedSpeed.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* FANSPositionSpeedSpeed */
typedef struct FANSPositionSpeedSpeed {
	FANSPosition_t	 position;
	FANSSpeedSpeed_t	 speed_seqOf;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} FANSPositionSpeedSpeed_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_FANSPositionSpeedSpeed;

#ifdef __cplusplus
}
#endif

#endif	/* _FANSPositionSpeedSpeed_H_ */
#include <asn_internal.h>
