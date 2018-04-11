/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "FANSACTwoWayDataLinkCommunications"
 * 	found in "fans-cpdlc.asn1"
 * 	`asn1c -fcompound-names -gen-PER`
 */

#ifndef	_FANSBeaconCode_H_
#define	_FANSBeaconCode_H_


#include <asn_application.h>

/* Including external dependencies */
#include "FANSBeaconCodeOctalDigit.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* FANSBeaconCode */
typedef struct FANSBeaconCode {
	A_SEQUENCE_OF(FANSBeaconCodeOctalDigit_t) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} FANSBeaconCode_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_FANSBeaconCode;

#ifdef __cplusplus
}
#endif

#endif	/* _FANSBeaconCode_H_ */
#include <asn_internal.h>
