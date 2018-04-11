/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "FANSACTwoWayDataLinkCommunications"
 * 	found in "fans-cpdlc.asn1"
 * 	`asn1c -fcompound-names -gen-PER`
 */

#ifndef	_FANSLongitudeDirection_H_
#define	_FANSLongitudeDirection_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum FANSLongitudeDirection {
	FANSLongitudeDirection_east	= 0,
	FANSLongitudeDirection_west	= 1
} e_FANSLongitudeDirection;

/* FANSLongitudeDirection */
typedef long	 FANSLongitudeDirection_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_FANSLongitudeDirection;
asn_struct_free_f FANSLongitudeDirection_free;
asn_struct_print_f FANSLongitudeDirection_print;
asn_constr_check_f FANSLongitudeDirection_constraint;
ber_type_decoder_f FANSLongitudeDirection_decode_ber;
der_type_encoder_f FANSLongitudeDirection_encode_der;
xer_type_decoder_f FANSLongitudeDirection_decode_xer;
xer_type_encoder_f FANSLongitudeDirection_encode_xer;
per_type_decoder_f FANSLongitudeDirection_decode_uper;
per_type_encoder_f FANSLongitudeDirection_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _FANSLongitudeDirection_H_ */
#include <asn_internal.h>
