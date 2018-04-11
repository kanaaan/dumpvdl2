/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "FANSACTwoWayDataLinkCommunications"
 * 	found in "fans-cpdlc.asn1"
 * 	`asn1c -fcompound-names -gen-PER`
 */

#ifndef	_FANSToFrom_H_
#define	_FANSToFrom_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum FANSToFrom {
	FANSToFrom_to	= 0,
	FANSToFrom_from	= 1
} e_FANSToFrom;

/* FANSToFrom */
typedef long	 FANSToFrom_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_FANSToFrom;
asn_struct_free_f FANSToFrom_free;
asn_struct_print_f FANSToFrom_print;
asn_constr_check_f FANSToFrom_constraint;
ber_type_decoder_f FANSToFrom_decode_ber;
der_type_encoder_f FANSToFrom_encode_der;
xer_type_decoder_f FANSToFrom_decode_xer;
xer_type_encoder_f FANSToFrom_encode_xer;
per_type_decoder_f FANSToFrom_decode_uper;
per_type_encoder_f FANSToFrom_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _FANSToFrom_H_ */
#include <asn_internal.h>
