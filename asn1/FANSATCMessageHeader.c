/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "FANSACTwoWayDataLinkCommunications"
 * 	found in "fans-cpdlc.asn1"
 * 	`asn1c -fcompound-names -gen-PER`
 */

#include "FANSATCMessageHeader.h"

static asn_TYPE_member_t asn_MBR_FANSATCMessageHeader_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct FANSATCMessageHeader, msgIdentificationNumber),
		(ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
		0,
		&asn_DEF_FANSMsgIdentificationNumber,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"msgIdentificationNumber"
		},
	{ ATF_POINTER, 2, offsetof(struct FANSATCMessageHeader, msgReferenceNumber),
		(ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
		0,
		&asn_DEF_FANSMsgReferenceNumber,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"msgReferenceNumber"
		},
	{ ATF_POINTER, 1, offsetof(struct FANSATCMessageHeader, timestamp),
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_FANSTimestamp,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"timestamp"
		},
};
static const int asn_MAP_FANSATCMessageHeader_oms_1[] = { 1, 2 };
static const ber_tlv_tag_t asn_DEF_FANSATCMessageHeader_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_FANSATCMessageHeader_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 0, 0, 1 }, /* msgIdentificationNumber */
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 1, -1, 0 }, /* msgReferenceNumber */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 2, 0, 0 } /* timestamp */
};
static asn_SEQUENCE_specifics_t asn_SPC_FANSATCMessageHeader_specs_1 = {
	sizeof(struct FANSATCMessageHeader),
	offsetof(struct FANSATCMessageHeader, _asn_ctx),
	asn_MAP_FANSATCMessageHeader_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_FANSATCMessageHeader_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_FANSATCMessageHeader = {
	"FANSATCMessageHeader",
	"FANSATCMessageHeader",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_FANSATCMessageHeader_tags_1,
	sizeof(asn_DEF_FANSATCMessageHeader_tags_1)
		/sizeof(asn_DEF_FANSATCMessageHeader_tags_1[0]), /* 1 */
	asn_DEF_FANSATCMessageHeader_tags_1,	/* Same as above */
	sizeof(asn_DEF_FANSATCMessageHeader_tags_1)
		/sizeof(asn_DEF_FANSATCMessageHeader_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_FANSATCMessageHeader_1,
	3,	/* Elements count */
	&asn_SPC_FANSATCMessageHeader_specs_1	/* Additional specs */
};

