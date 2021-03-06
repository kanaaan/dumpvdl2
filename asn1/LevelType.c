/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "PMCPDLCMessageSetVersion1"
 * 	found in "atn-cpdlc.asn1"
 * 	`asn1c -fcompound-names -gen-PER`
 */

#include "LevelType.h"

static asn_per_constraints_t asn_PER_type_LevelType_constr_1 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  3 }	/* (0..3) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_LevelType_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct LevelType, choice.levelFeet),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_LevelFeet,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"levelFeet"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LevelType, choice.levelMeters),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_LevelMeters,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"levelMeters"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LevelType, choice.levelFlightLevel),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_LevelFlightLevel,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"levelFlightLevel"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct LevelType, choice.levelFlightLevelMetric),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_LevelFlightLevelMetric,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"levelFlightLevelMetric"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_LevelType_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* levelFeet */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* levelMeters */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* levelFlightLevel */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* levelFlightLevelMetric */
};
static asn_CHOICE_specifics_t asn_SPC_LevelType_specs_1 = {
	sizeof(struct LevelType),
	offsetof(struct LevelType, _asn_ctx),
	offsetof(struct LevelType, present),
	sizeof(((struct LevelType *)0)->present),
	asn_MAP_LevelType_tag2el_1,
	4,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_LevelType = {
	"LevelType",
	"LevelType",
	CHOICE_free,
	CHOICE_print,
	CHOICE_constraint,
	CHOICE_decode_ber,
	CHOICE_encode_der,
	CHOICE_decode_xer,
	CHOICE_encode_xer,
	CHOICE_decode_uper,
	CHOICE_encode_uper,
	CHOICE_outmost_tag,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	&asn_PER_type_LevelType_constr_1,
	asn_MBR_LevelType_1,
	4,	/* Elements count */
	&asn_SPC_LevelType_specs_1	/* Additional specs */
};

