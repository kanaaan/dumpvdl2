/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "FANSACTwoWayDataLinkCommunications"
 * 	found in "fans-cpdlc.asn1"
 * 	`asn1c -fcompound-names -gen-PER`
 */

#ifndef	_FANSATWAltitudeSequence_H_
#define	_FANSATWAltitudeSequence_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct FANSATWAltitude;

/* FANSATWAltitudeSequence */
typedef struct FANSATWAltitudeSequence {
	A_SEQUENCE_OF(struct FANSATWAltitude) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} FANSATWAltitudeSequence_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_FANSATWAltitudeSequence;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "FANSATWAltitude.h"

#endif	/* _FANSATWAltitudeSequence_H_ */
#include <asn_internal.h>
