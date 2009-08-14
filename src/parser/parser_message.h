/*
 * Copyright (C) 2008 Search Solution Corporation. All rights reserved by Search Solution.
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or 
 *   (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */


/*
 * parser_message.h - Parser error message numbers
 *                    (syntax, semantics, and runtime)
 */

#ifndef _PARSER_MESSAGE_H_
#define _PARSER_MESSAGE_H_

#ident "$Id$"

/*
 * Message set id in the message catalog MSGCAT_CATALOG_CUBRID.
 * These define the $set numbers within the catalog file of the message
 * for each utility.
 */

/* Message id in the set MSGCAT_SET_PARSER_SYNTAX */
#define MSGCAT_SYNTAX_NO(n)                             n
#define MSGCAT_SYNTAX_ERROR_MSG1                        MSGCAT_SYNTAX_NO(1)
#define MSGCAT_SYNTAX_ERROR_MSG2                        MSGCAT_SYNTAX_NO(2)
#define MSGCAT_SYNTAX_LEXICAL_ERROR                     MSGCAT_SYNTAX_NO(3)
#define MSGCAT_SYNTAX_READ_UNCOMMIT                     MSGCAT_SYNTAX_NO(4)
#define MSGCAT_SYNTAX_MAX_STRINGLEN                     MSGCAT_SYNTAX_NO(5)
#define MSGCAT_SYNTAX_INT_OVERFLOW                      MSGCAT_SYNTAX_NO(6)
#define MSGCAT_SYNTAX_MAX_BITLEN                        MSGCAT_SYNTAX_NO(7)
#define MSGCAT_SYNTAX_JOIN_COND_SUBQ                    MSGCAT_SYNTAX_NO(8)
#define MSGCAT_SYNTAX_ATTR_IN_PRIVILEGE                 MSGCAT_SYNTAX_NO(9)
#define MSGCAT_SYNTAX_KEYWORD_ERROR                     MSGCAT_SYNTAX_NO(10)
#define MSGCAT_SYNTAX_TOKEN_TOO_LONG                    MSGCAT_SYNTAX_NO(11)
#define MSGCAT_SYNTAX_INVALID_DATA_TYPE                 MSGCAT_SYNTAX_NO(12)
#define MSGCAT_SYNTAX_INVALID_ATTACH                    MSGCAT_SYNTAX_NO(13)
#define MSGCAT_SYNTAX_INVALID_PREPARE                   MSGCAT_SYNTAX_NO(14)
#define MSGCAT_SYNTAX_INVALID_EXECUTE                   MSGCAT_SYNTAX_NO(15)
#define MSGCAT_SYNTAX_INVALID_SCOPE                     MSGCAT_SYNTAX_NO(16)
#define MSGCAT_SYNTAX_INVALID_SET_SYS_PARAM             MSGCAT_SYNTAX_NO(17)
#define MSGCAT_SYNTAX_INVALID_SET_TRAN                  MSGCAT_SYNTAX_NO(18)
#define MSGCAT_SYNTAX_INVALID_SET_TRIGGER_TRACE         MSGCAT_SYNTAX_NO(19)
#define MSGCAT_SYNTAX_INVALID_SET_TRIGGER_DEPTH         MSGCAT_SYNTAX_NO(20)
#define MSGCAT_SYNTAX_INVALID_SET_OPT_LEVEL             MSGCAT_SYNTAX_NO(21)
#define MSGCAT_SYNTAX_INVALID_SET_OPT_COST              MSGCAT_SYNTAX_NO(22)
#define MSGCAT_SYNTAX_INVALID_GET_OPT_LEVEL             MSGCAT_SYNTAX_NO(23)
#define MSGCAT_SYNTAX_INVALID_GET_OPT_COST              MSGCAT_SYNTAX_NO(24)
#define MSGCAT_SYNTAX_INVALID_GET_TRAN_ISOL             MSGCAT_SYNTAX_NO(25)
#define MSGCAT_SYNTAX_INVALID_GET_TRAN_LOCK             MSGCAT_SYNTAX_NO(26)
#define MSGCAT_SYNTAX_INVALID_GET_TRIGGER_TRACE         MSGCAT_SYNTAX_NO(27)
#define MSGCAT_SYNTAX_INVALID_GET_TRIGGER_DEPTH         MSGCAT_SYNTAX_NO(28)
#define MSGCAT_SYNTAX_INVALID_GET_STAT                  MSGCAT_SYNTAX_NO(29)
#define MSGCAT_SYNTAX_INVALID_CREATE_INDEX              MSGCAT_SYNTAX_NO(30)
#define MSGCAT_SYNTAX_INVALID_CREATE_USER               MSGCAT_SYNTAX_NO(31)
#define MSGCAT_SYNTAX_INVALID_CREATE_TRIGGER            MSGCAT_SYNTAX_NO(32)
#define MSGCAT_SYNTAX_INVALID_CREATE_SERIAL             MSGCAT_SYNTAX_NO(33)
#define MSGCAT_SYNTAX_INVALID_CREATE_PROCEDURE          MSGCAT_SYNTAX_NO(34)
#define MSGCAT_SYNTAX_INVALID_CREATE_FUNCTION           MSGCAT_SYNTAX_NO(35)
#define MSGCAT_SYNTAX_INVALID_GROUPS                    MSGCAT_SYNTAX_NO(36)
#define MSGCAT_SYNTAX_INVALID_MEMBERS                   MSGCAT_SYNTAX_NO(37)
#define MSGCAT_SYNTAX_INVALID_PASSWORD                  MSGCAT_SYNTAX_NO(38)
#define MSGCAT_SYNTAX_MISSING_AUTH_COMMAND_LIST         MSGCAT_SYNTAX_NO(39)
#define MSGCAT_SYNTAX_MISSING_CLASS_SPEC_LIST           MSGCAT_SYNTAX_NO(40)
#define MSGCAT_SYNTAX_MISSING_IDENTIFIER_LIST           MSGCAT_SYNTAX_NO(41)
#define MSGCAT_SYNTAX_MISSING_EXPRESSION                MSGCAT_SYNTAX_NO(42)
#define MSGCAT_SYNTAX_INVALID_IDENTIFIER                MSGCAT_SYNTAX_NO(43)
#define MSGCAT_SYNTAX_INVALID_SUBSTRING                 MSGCAT_SYNTAX_NO(44)
#define MSGCAT_SYNTAX_INVALID_TRIM                      MSGCAT_SYNTAX_NO(45)
#define MSGCAT_SYNTAX_INVALID_CAST                      MSGCAT_SYNTAX_NO(46)
#define MSGCAT_SYNTAX_INVALID_ADD_MONTHS                MSGCAT_SYNTAX_NO(47)
#define MSGCAT_SYNTAX_INVALID_OCTET_LENGTH              MSGCAT_SYNTAX_NO(48)
#define MSGCAT_SYNTAX_INVALID_BIT_LENGTH                MSGCAT_SYNTAX_NO(49)
#define MSGCAT_SYNTAX_INVALID_LOWER                     MSGCAT_SYNTAX_NO(50)
#define MSGCAT_SYNTAX_INVALID_UPPER                     MSGCAT_SYNTAX_NO(51)
#define MSGCAT_SYNTAX_INVALID_TRANSLATE                 MSGCAT_SYNTAX_NO(52)
#define MSGCAT_SYNTAX_INVALID_REPLACE                   MSGCAT_SYNTAX_NO(53)
#define MSGCAT_SYNTAX_INVALID_TO_NUMBER                 MSGCAT_SYNTAX_NO(54)
#define MSGCAT_SYNTAX_INVALID_STRCAT                    MSGCAT_SYNTAX_NO(55)
#define MSGCAT_SYNTAX_INVALID_ALTER                     MSGCAT_SYNTAX_NO(56)
#define MSGCAT_SYNTAX_INVALID_DROP                      MSGCAT_SYNTAX_NO(57)
#define MSGCAT_SYNTAX_INVALID_CREATE                    MSGCAT_SYNTAX_NO(58)
#define MSGCAT_SYNTAX_INVALID_RELATIONAL_OP             MSGCAT_SYNTAX_NO(59)
#define MSGCAT_SYNTAX_INVALID_EQUAL_OP                  MSGCAT_SYNTAX_NO(60)
#define MSGCAT_SYNTAX_INVALID_NOT_EQUAL                 MSGCAT_SYNTAX_NO(61)
#define MSGCAT_SYNTAX_INVALID_MINUS_VALUE               MSGCAT_SYNTAX_NO(62)
#define MSGCAT_SYNTAX_DUPLICATED_REF_RULE               MSGCAT_SYNTAX_NO(63)

/* Message id in the set MSGCAT_SET_PARSER_SEMANTIC */
#define MSGCAT_SEMANTIC_NO(n)			n
#define MSGCAT_SEMANTIC_OUT_OF_MEMORY           MSGCAT_SEMANTIC_NO(1)
#define MSGCAT_SEMANTIC_UNKNOWN_FUNCTION        MSGCAT_SEMANTIC_NO(2)
#define MSGCAT_SEMANTIC_CANT_FIND_LDB           MSGCAT_SEMANTIC_NO(3)
#define MSGCAT_SEMANTIC_ARITY_MISMATCH          MSGCAT_SEMANTIC_NO(4)
#define MSGCAT_SEMANTIC_UNION_INCOMPATIBLE      MSGCAT_SEMANTIC_NO(5)
#define MSGCAT_SEMANTIC_IS_NOT_DEFINED          MSGCAT_SEMANTIC_NO(6)
#define MSGCAT_SEMANTIC_CAN_NOT_BE_VCLASS       MSGCAT_SEMANTIC_NO(7)
#define MSGCAT_SEMANTIC_CAN_NOT_BE_PROXY        MSGCAT_SEMANTIC_NO(8)
#define MSGCAT_SEMANTIC_CAN_NOT_BE_CLASS        MSGCAT_SEMANTIC_NO(9)
#define MSGCAT_SEMANTIC_NOT_ATTRIBUTE_OF        MSGCAT_SEMANTIC_NO(10)
#define MSGCAT_SEMANTIC_HEIR_CANT_CHANGE_IT     MSGCAT_SEMANTIC_NO(11)
#define MSGCAT_SEMANTIC_CLASS_DOES_NOT_EXIST    MSGCAT_SEMANTIC_NO(12)
#define MSGCAT_SEMANTIC_IS_NOT_A                MSGCAT_SEMANTIC_NO(13)
#define MSGCAT_SEMANTIC_NOT_METHOD_OR_ATTR      MSGCAT_SEMANTIC_NO(14)
#define MSGCAT_SEMANTIC_HAVE_NO_QUERY_SPEC      MSGCAT_SEMANTIC_NO(15)
#define MSGCAT_SEMANTIC_NOT_DEFINED_IN_DB       MSGCAT_SEMANTIC_NO(16)
#define MSGCAT_SEMANTIC_NOT_SUPERCLASS_OF       MSGCAT_SEMANTIC_NO(17)
#define MSGCAT_SEMANTIC_NONCLASS_PARENT         MSGCAT_SEMANTIC_NO(18)
#define MSGCAT_SEMANTIC_NONVCLASS_PARENT        MSGCAT_SEMANTIC_NO(19)
#define MSGCAT_SEMANTIC_NONPROXY_PARENT         MSGCAT_SEMANTIC_NO(20)
#define MSGCAT_SEMANTIC_ALREADY_SUPERCLASS      MSGCAT_SEMANTIC_NO(21)
#define MSGCAT_SEMANTIC_SUPERCLASS_CYCLE        MSGCAT_SEMANTIC_NO(22)
#define MSGCAT_SEMANTIC_ALREADY_SUBCLASS        MSGCAT_SEMANTIC_NO(23)
#define MSGCAT_SEMANTIC_NOT_SINGLE_VALUED       MSGCAT_SEMANTIC_NO(24)
#define MSGCAT_SEMANTIC_COL_CNT_NE_INTO_CNT     MSGCAT_SEMANTIC_NO(25)
#define MSGCAT_SEMANTIC_CLASS_EXISTS            MSGCAT_SEMANTIC_NO(26)
#define MSGCAT_SEMANTIC_NONEXISTENT_SUPCLASS    MSGCAT_SEMANTIC_NO(27)
#define MSGCAT_SEMANTIC_WANT_SUBCLASS_CLAUSE    MSGCAT_SEMANTIC_NO(28)
#define MSGCAT_SEMANTIC_NOT_IN_SUBCLASS_LIST    MSGCAT_SEMANTIC_NO(29)
#define MSGCAT_SEMANTIC_CLASS_NO_QUERY_SPEC     MSGCAT_SEMANTIC_NO(30)
#define MSGCAT_SEMANTIC_NOT_A_REGISTERED_LDB    MSGCAT_SEMANTIC_NO(31)
#define MSGCAT_SEMANTIC_IMMUTABLE_OBJECT_ID     MSGCAT_SEMANTIC_NO(32)
#define MSGCAT_SEMANTIC_PROXY_GT_1_QRY_SPEC     MSGCAT_SEMANTIC_NO(33)
#define MSGCAT_SEMANTIC_ATT_CNT_NE_COL_CNT      MSGCAT_SEMANTIC_NO(34)
#define MSGCAT_SEMANTIC_MISSING_ATTR_NAME       MSGCAT_SEMANTIC_NO(35)
#define MSGCAT_SEMANTIC_ATT_INCOMPATIBLE_COL    MSGCAT_SEMANTIC_NO(36)
#define MSGCAT_SEMANTIC_IS_NOT_A_CLASS          MSGCAT_SEMANTIC_NO(37)
#define MSGCAT_SEMANTIC_NO_INDEX_ON_VCLASS      MSGCAT_SEMANTIC_NO(38)
#define MSGCAT_SEMANTIC_INDEX_ONLY_ON_1_ATTR    MSGCAT_SEMANTIC_NO(39)
#define MSGCAT_SEMANTIC_DELETE_1_CLASS_ONLY     MSGCAT_SEMANTIC_NO(40)
#define MSGCAT_SEMANTIC_RESOLUTION_FAILED       MSGCAT_SEMANTIC_NO(41)
#define MSGCAT_SEMANTIC_DELETE_DERIVED_TABLE    MSGCAT_SEMANTIC_NO(42)
#define MSGCAT_SEMANTIC_USER_IS_NOT_IN_DB       MSGCAT_SEMANTIC_NO(43)
#define MSGCAT_SEMANTIC_UPDATE_NO_AGGREGATE     MSGCAT_SEMANTIC_NO(44)
#define MSGCAT_SEMANTIC_CLASS_ATTR_DUPLICATED   MSGCAT_SEMANTIC_NO(45)
#define MSGCAT_SEMANTIC_GT_1_ASSIGNMENT_TO      MSGCAT_SEMANTIC_NO(46)
#define MSGCAT_SEMANTIC_SORT_SPEC_WANT_NUM      MSGCAT_SEMANTIC_NO(47)
#define MSGCAT_SEMANTIC_SORT_SPEC_RANGE_ERR     MSGCAT_SEMANTIC_NO(48)
#define MSGCAT_SEMANTIC_ORDERBY_IS_NOT_INT      MSGCAT_SEMANTIC_NO(49)
#define MSGCAT_SEMANTIC_SORT_SPEC_NOT_EXIST     MSGCAT_SEMANTIC_NO(50)
#define MSGCAT_SEMANTIC_SORT_DIR_CONFLICT       MSGCAT_SEMANTIC_NO(51)
#define MSGCAT_SEMANTIC_SORT_SPEC_NAN_PATH      MSGCAT_SEMANTIC_NO(52)
#define MSGCAT_SEMANTIC_INS_EXPR_IN_INSERT      MSGCAT_SEMANTIC_NO(53)
#define MSGCAT_SEMANTIC_ATT_CNT_COL_CNT_NE      MSGCAT_SEMANTIC_NO(54)
#define MSGCAT_SEMANTIC_ATT_CNT_VAL_CNT_NE      MSGCAT_SEMANTIC_NO(55)
#define MSGCAT_SEMANTIC_DATA_OVERFLOW_ON        MSGCAT_SEMANTIC_NO(56)
#define MSGCAT_SEMANTIC_INCOMP_TYPE_ON_ATTR     MSGCAT_SEMANTIC_NO(57)
#define MSGCAT_SEMANTIC_NOT_1_CLASS_SELECT      MSGCAT_SEMANTIC_NO(58)
#define MSGCAT_SEMANTIC_NO_STAR_IN_PROXY        MSGCAT_SEMANTIC_NO(59)
#define MSGCAT_SEMANTIC_NOT_VCLASS_NOR_PROXY    MSGCAT_SEMANTIC_NO(60)
#define MSGCAT_SEMANTIC_GT_1_ISOLATION_LVL      MSGCAT_SEMANTIC_NO(61)
#define MSGCAT_SEMANTIC_GT_1_TIMEOUT_CLAUSES    MSGCAT_SEMANTIC_NO(62)
#define MSGCAT_SEMANTIC_NO_ISOLATION_LVL_MSG    MSGCAT_SEMANTIC_NO(63)
#define MSGCAT_SEMANTIC_BETWEEN_NOT_ON_TYPES    MSGCAT_SEMANTIC_NO(64)
#define MSGCAT_SEMANTIC_OP_NOT_DEFINED_ON       MSGCAT_SEMANTIC_NO(65)
#define MSGCAT_SEMANTIC_FUNCTION_NO_ARGS        MSGCAT_SEMANTIC_NO(66)
#define MSGCAT_SEMANTIC_INCOMPATIBLE_OPDS       MSGCAT_SEMANTIC_NO(67)
#define MSGCAT_SEMANTIC_AGG_FUN_WANT_1_ARG      MSGCAT_SEMANTIC_NO(68)
#define MSGCAT_SEMANTIC_ZERO_DIVIDE             MSGCAT_SEMANTIC_NO(69)
#define MSGCAT_SEMANTIC_OVERFLOW_COERCING_TO    MSGCAT_SEMANTIC_NO(70)
#define MSGCAT_SEMANTIC_CANT_COERCE_TO          MSGCAT_SEMANTIC_NO(71)
#define MSGCAT_SEMANTIC_MUST_BE_SET_MSET_SEQ    MSGCAT_SEMANTIC_NO(72)
#define MSGCAT_SEMANTIC_GT_1_SET_ELEM_TYPE      MSGCAT_SEMANTIC_NO(73)
#define MSGCAT_SEMANTIC_GT_1_DERIVED_COL_NAM    MSGCAT_SEMANTIC_NO(74)
#define MSGCAT_SEMANTIC_NO_DERIVED_COL_NAM      MSGCAT_SEMANTIC_NO(75)
#define MSGCAT_SEMANTIC_ATT_CNT_NE_DERIVED_C    MSGCAT_SEMANTIC_NO(76)
#define MSGCAT_SEMANTIC_NO_ATTRIBUTES_IN_CLS    MSGCAT_SEMANTIC_NO(77)
#define MSGCAT_SEMANTIC_WANT_SINGLE_TABLE_IN    MSGCAT_SEMANTIC_NO(78)
#define MSGCAT_SEMANTIC_AMBIGUOUS_EXPOSED_NM    MSGCAT_SEMANTIC_NO(79)
#define MSGCAT_SEMANTIC_WANT_NO_DERIVED_COLS    MSGCAT_SEMANTIC_NO(80)
#define MSGCAT_SEMANTIC_WANT_CORRELATION_NAM    MSGCAT_SEMANTIC_NO(81)
#define MSGCAT_SEMANTIC_SELECT_AUTH_FAILURE     MSGCAT_SEMANTIC_NO(82)
#define MSGCAT_SEMANTIC_WANT_NO_REF_TO_DRVTB    MSGCAT_SEMANTIC_NO(83)
#define MSGCAT_SEMANTIC_PATH_CORR_OUTSIDE       MSGCAT_SEMANTIC_NO(84)
#define MSGCAT_SEMANTIC_AMBIGUOUS_REF_TO        MSGCAT_SEMANTIC_NO(85)
#define MSGCAT_SEMANTIC_CLASS_HAS_NO_ATTR       MSGCAT_SEMANTIC_NO(86)
#define MSGCAT_SEMANTIC_CLASSES_HAVE_NO_ATTR    MSGCAT_SEMANTIC_NO(87)
#define MSGCAT_SEMANTIC_CLASS_DOES_NOT_HAVE     MSGCAT_SEMANTIC_NO(88)
#define MSGCAT_SEMANTIC_IS_NOT_OBJECT_TYPE      MSGCAT_SEMANTIC_NO(89)
#define MSGCAT_SEMANTIC_SELECTOR_UNRESOLVED     MSGCAT_SEMANTIC_NO(90)
#define MSGCAT_SEMANTIC_SELECTOR_TO_NON_CLS     MSGCAT_SEMANTIC_NO(91)
#define MSGCAT_SEMANTIC_SELECTOR_DEFINE_SELF    MSGCAT_SEMANTIC_NO(92)
#define MSGCAT_SEMANTIC_CYCLIC_SELECTOR         MSGCAT_SEMANTIC_NO(93)
#define MSGCAT_SEMANTIC_SELECTOR_REDEFINED      MSGCAT_SEMANTIC_NO(94)
#define MSGCAT_SEMANTIC_DOM_OBJ_HASNO_ATT_X     MSGCAT_SEMANTIC_NO(95)
#define MSGCAT_SEMANTIC_EXCEPTSPEC_NOT_HEIR     MSGCAT_SEMANTIC_NO(96)
#define MSGCAT_SEMANTIC_SPEC_EXCLUDES_ALL       MSGCAT_SEMANTIC_NO(97)
#define MSGCAT_SEMANTIC_INCONSISTENT_PATH       MSGCAT_SEMANTIC_NO(98)
#define MSGCAT_SEMANTIC_UNDEFINED_ARGUMENT      MSGCAT_SEMANTIC_NO(99)
#define MSGCAT_SEMANTIC_ARG_IS_NOT_AN_OBJECT            MSGCAT_SEMANTIC_NO(100)
#define MSGCAT_SEMANTIC_NOT_CLASS_ATTR_MTHD             MSGCAT_SEMANTIC_NO(101)
#define MSGCAT_SEMANTIC_WANT_NO_INTO_CLAUSE             MSGCAT_SEMANTIC_NO(102)
#define MSGCAT_SEMANTIC_WANT_NO_AGGREGATE               MSGCAT_SEMANTIC_NO(103)
#define MSGCAT_SEMANTIC_WANT_NO_DISTINCT                MSGCAT_SEMANTIC_NO(104)
#define MSGCAT_SEMANTIC_WANT_SIMPLE_SELECT              MSGCAT_SEMANTIC_NO(105)
#define MSGCAT_SEMANTIC_WANT_1_TBL_SELECT               MSGCAT_SEMANTIC_NO(106)
#define MSGCAT_SEMANTIC_USER_DOESNT_OWN_CLS             MSGCAT_SEMANTIC_NO(107)
#define MSGCAT_SEMANTIC_PROXIES_ON_SAME_ENT             MSGCAT_SEMANTIC_NO(108)
#define MSGCAT_SEMANTIC_WANT_NO_OBJ_IN_SETS             MSGCAT_SEMANTIC_NO(109)
#define MSGCAT_SEMANTIC_WANT_LOGICAL_WHERE              MSGCAT_SEMANTIC_NO(110)
#define MSGCAT_SEMANTIC_WANT_ESC_LIT_STRING             MSGCAT_SEMANTIC_NO(111)
#define MSGCAT_SEMANTIC_INV_PREC_SCALE                  MSGCAT_SEMANTIC_NO(112)
#define MSGCAT_SEMANTIC_INV_PREC                        MSGCAT_SEMANTIC_NO(113)
#define MSGCAT_SEMANTIC_PREC_TOO_BIG                    MSGCAT_SEMANTIC_NO(114)
#define MSGCAT_SEMANTIC_METHOD_NO_RET_TYPE              MSGCAT_SEMANTIC_NO(115)
#define MSGCAT_SEMANTIC_METH_ARG_NE_DEFINED             MSGCAT_SEMANTIC_NO(116)
#define MSGCAT_SEMANTIC_METH_NO_TARGET                  MSGCAT_SEMANTIC_NO(117)
#define MSGCAT_SEMANTIC_METH_DOESNT_EXIST               MSGCAT_SEMANTIC_NO(118)
#define MSGCAT_SEMANTIC_METH_MIX_INST_CLASS             MSGCAT_SEMANTIC_NO(119)
#define MSGCAT_SEMANTIC_METH_MIX_CLASS_INST             MSGCAT_SEMANTIC_NO(120)
#define MSGCAT_SEMANTIC_METH_CLASS_OBJ_REQ              MSGCAT_SEMANTIC_NO(121)
#define MSGCAT_SEMANTIC_METH_TARGET_NOT_OBJ             MSGCAT_SEMANTIC_NO(122)
#define MSGCAT_SEMANTIC_METH_NOT_TYPED                  MSGCAT_SEMANTIC_NO(123)
#define MSGCAT_SEMANTIC_TIME_UNDERFLOW                  MSGCAT_SEMANTIC_NO(124)
#define MSGCAT_SEMANTIC_DATE_UNDERFLOW                  MSGCAT_SEMANTIC_NO(125)
#define MSGCAT_SEMANTIC_ILLEGAL_LHS                     MSGCAT_SEMANTIC_NO(126)
#define MSGCAT_SEMANTIC_METH_CORR_SET_EXPR              MSGCAT_SEMANTIC_NO(127)
#define MSGCAT_SEMANTIC_QSPEC_COL_NOT_NA                MSGCAT_SEMANTIC_NO(128)
#define MSGCAT_SEMANTIC_QSPEC_IS_ALL_NA                 MSGCAT_SEMANTIC_NO(129)
#define MSGCAT_SEMANTIC_WANT_NO_VOBJ_IN_SETS            MSGCAT_SEMANTIC_NO(130)
#define MSGCAT_SEMANTIC_WANT_STRING_VALUE               MSGCAT_SEMANTIC_NO(131)
#define MSGCAT_SEMANTIC_WANT_STMT_OR_STRING             MSGCAT_SEMANTIC_NO(132)
#define MSGCAT_SEMANTIC_WANT_SIMPLE_QS_COL              MSGCAT_SEMANTIC_NO(133)
#define MSGCAT_SEMANTIC_UNIMPLEMENTED_CONSTRAINT        MSGCAT_SEMANTIC_NO(134)
#define MSGCAT_SEMANTIC_WANT_NO_CONSTRAINTS             MSGCAT_SEMANTIC_NO(135)
#define MSGCAT_SEMANTIC_COERCE_UNSUPPORTED              MSGCAT_SEMANTIC_NO(136)
#define MSGCAT_SEMANTIC_INVALID_BITSTRING               MSGCAT_SEMANTIC_NO(137)
#define MSGCAT_SEMANTIC_OP_NOT_DEFINED_ON_1             MSGCAT_SEMANTIC_NO(138)
#define MSGCAT_SEMANTIC_OP_NOT_DEFINED_ON_3             MSGCAT_SEMANTIC_NO(139)
#define MSGCAT_SEMANTIC_ILLEGAL_DYNAMIC_HOST_VAR        MSGCAT_SEMANTIC_NO(140)
#define MSGCAT_SEMANTIC_GEN_FUNC_TOO_MANY_ARGS          MSGCAT_SEMANTIC_NO(141)
#define MSGCAT_SEMANTIC_SELECTOR_NOT_SUBCLASS           MSGCAT_SEMANTIC_NO(142)
#define MSGCAT_SEMANTIC_CANT_EXTRACT_FROM               MSGCAT_SEMANTIC_NO(143)
#define MSGCAT_SEMANTIC_WANT_NO_ORDERBY_CLAUSE          MSGCAT_SEMANTIC_NO(144)
#define MSGCAT_SEMANTIC_WANT_LOGICAL_CASE_COND          MSGCAT_SEMANTIC_NO(145)
#define MSGCAT_SEMANTIC_WANT_TYPE                       MSGCAT_SEMANTIC_NO(146)
#define MSGCAT_SEMANTIC_SERIAL_ALREADY_EXIST            MSGCAT_SEMANTIC_NO(147)
#define MSGCAT_SEMANTIC_SERIAL_NOT_DEFINED              MSGCAT_SEMANTIC_NO(148)
#define MSGCAT_SEMANTIC_SERIAL_INC_VAL_ZERO             MSGCAT_SEMANTIC_NO(149)
#define MSGCAT_SEMANTIC_SERIAL_MAX_VAL_OVERFLOW         MSGCAT_SEMANTIC_NO(150)
#define MSGCAT_SEMANTIC_SERIAL_MIN_VAL_INVALID          MSGCAT_SEMANTIC_NO(151)
#define MSGCAT_SEMANTIC_SERIAL_INC_VAL_INVALID          MSGCAT_SEMANTIC_NO(152)
#define MSGCAT_SEMANTIC_SERIAL_MIN_VAL_UNDERFLOW        MSGCAT_SEMANTIC_NO(153)
#define MSGCAT_SEMANTIC_SERIAL_MAX_VAL_INVALID          MSGCAT_SEMANTIC_NO(154)
#define MSGCAT_SEMANTIC_SERIAL_ALTER_NO_OPTION          MSGCAT_SEMANTIC_NO(155)
#define MSGCAT_SEMANTIC_SERIAL_ALTER_NOT_ALLOWED        MSGCAT_SEMANTIC_NO(156)
#define MSGCAT_SEMANTIC_SERIAL_VALUE_OVERFLOW           MSGCAT_SEMANTIC_NO(157)
#define MSGCAT_SEMANTIC_SERIAL_IO_ERROR                 MSGCAT_SEMANTIC_NO(158)
#define MSGCAT_SEMANTIC_USING_INDEX_ERR_1               MSGCAT_SEMANTIC_NO(159)
#define MSGCAT_SEMANTIC_USING_INDEX_ERR_2               MSGCAT_SEMANTIC_NO(160)
#define MSGCAT_SEMANTIC_USING_INDEX_ERR_3               MSGCAT_SEMANTIC_NO(161)
#define MSGCAT_SEMANTIC_INSTNUM_COMPATIBILITY_ERR       MSGCAT_SEMANTIC_NO(162)
#define MSGCAT_SEMANTIC_ORDERBYNUM_SELECT_LIST_ERR      MSGCAT_SEMANTIC_NO(163)
#define MSGCAT_SEMANTIC_OUTERJOIN_PATH_EXPR             MSGCAT_SEMANTIC_NO(164)
#define MSGCAT_SEMANTIC_OUTERJOIN_SCOPE                 MSGCAT_SEMANTIC_NO(165)
#define MSGCAT_SEMANTIC_OUTERJOIN_DERIVED               MSGCAT_SEMANTIC_NO(166)
#define MSGCAT_SEMANTIC_WANT_SAME_LDB_INSERT            MSGCAT_SEMANTIC_NO(167)
#define MSGCAT_SEMANTIC_NOT_SINGLE_COL                  MSGCAT_SEMANTIC_NO(168)
#define MSGCAT_SEMANTIC_ILLEGAL_RHS                     MSGCAT_SEMANTIC_NO(169)
#define MSGCAT_SEMANTIC_OUTERJOIN_JOIN_COND_SUBQ        MSGCAT_SEMANTIC_NO(170)
#define MSGCAT_SEMANTIC_INVALID_PARTITION_DEFINITION    MSGCAT_SEMANTIC_NO(171)
#define MSGCAT_SEMANTIC_NO_PARTITION_COLUMN             MSGCAT_SEMANTIC_NO(172)
#define MSGCAT_SEMANTIC_ONLYONE_PARTITION_COLUMN        MSGCAT_SEMANTIC_NO(173)
#define MSGCAT_SEMANTIC_INVALID_PARTITION_COLUMN_TYPE   MSGCAT_SEMANTIC_NO(174)
#define MSGCAT_SEMANTIC_DUPLICATE_PARTITION_DEF         MSGCAT_SEMANTIC_NO(175)
#define MSGCAT_SEMANTIC_CONSTANT_TYPE_MISMATCH          MSGCAT_SEMANTIC_NO(176)
#define MSGCAT_SEMANTIC_INVALID_PARTITION_SIZE          MSGCAT_SEMANTIC_NO(177)
#define MSGCAT_SEMANTIC_IS_NOT_PARTITIONED_CLASS        MSGCAT_SEMANTIC_NO(178)
#define MSGCAT_SEMANTIC_ALREADY_PARTITIONED_CLASS       MSGCAT_SEMANTIC_NO(179)
#define MSGCAT_SEMANTIC_INVALID_PARTITION_REQUEST       MSGCAT_SEMANTIC_NO(180)
#define MSGCAT_SEMANTIC_PARTITION_KEY_COLUMN            MSGCAT_SEMANTIC_NO(181)
#define MSGCAT_SEMANTIC_CANT_PARTITION_MNG_TRIGGERS     MSGCAT_SEMANTIC_NO(182)
#define MSGCAT_SEMANTIC_PARTITION_DOES_NOT_EXIST        MSGCAT_SEMANTIC_NO(183)
#define MSGCAT_SEMANTIC_PARTITION_TYPE_MISMATCH         MSGCAT_SEMANTIC_NO(184)
#define MSGCAT_SEMANTIC_INVALID_PARTITION_INFO          MSGCAT_SEMANTIC_NO(185)
#define MSGCAT_SEMANTIC_IS_NOT_END_OF_PARTITION         MSGCAT_SEMANTIC_NO(186)
#define MSGCAT_SEMANTIC_DATA_LOSS_IS_NOT_ALLOWED        MSGCAT_SEMANTIC_NO(187)
#define MSGCAT_SEMANTIC_PARTITION_RANGE_INVALID         MSGCAT_SEMANTIC_NO(188)
#define MSGCAT_SEMANTIC_CLASS_ATT_CANT_BE_AUTOINC       MSGCAT_SEMANTIC_NO(189)
#define MSGCAT_SEMANTIC_VCLASS_ATT_CANT_BE_AUTOINC      MSGCAT_SEMANTIC_NO(190)
#define MSGCAT_SEMANTIC_INVALID_AUTO_INCREMENT_DOMAIN   MSGCAT_SEMANTIC_NO(191)
#define MSGCAT_SEMANTIC_CANT_ASSIGN_FK_CACHE_ATTR       MSGCAT_SEMANTIC_NO(192)
#define MSGCAT_SEMANTIC_INDEX_ATTR_DUPLICATED           MSGCAT_SEMANTIC_NO(193)
#define MSGCAT_SEMANTIC_INVALID_INTERNAL_FUNCTION       MSGCAT_SEMANTIC_NO(194)

/* Message id in the set MSGCAT_SET_PARSER_RUNTIME */
#define MSGCAT_RUNTIME_NO(n)				n
#define MSGCAT_RUNTIME_OUT_OF_MEMORY                    MSGCAT_RUNTIME_NO(1)
#define MSGCAT_RUNTIME_XACT_ISO_LVL_MSG                 MSGCAT_RUNTIME_NO(2)
#define MSGCAT_RUNTIME_TIMEOUT_VALUE_MSG                MSGCAT_RUNTIME_NO(3)
#define MSGCAT_RUNTIME_ISO_LVL_SET_TO_MSG               MSGCAT_RUNTIME_NO(4)
#define MSGCAT_RUNTIME_READCOM_S_READUNC_I              MSGCAT_RUNTIME_NO(5)
#define MSGCAT_RUNTIME_READCOM_S_READCOM_I              MSGCAT_RUNTIME_NO(6)
#define MSGCAT_RUNTIME_REPREAD_S_READUNC_I              MSGCAT_RUNTIME_NO(7)
#define MSGCAT_RUNTIME_REPREAD_S_READCOM_I              MSGCAT_RUNTIME_NO(8)
#define MSGCAT_RUNTIME_REPREAD_S_REPREAD_I              MSGCAT_RUNTIME_NO(9)
#define MSGCAT_RUNTIME_NO_GROUPBY_ALLOWED               MSGCAT_RUNTIME_NO(10)
#define MSGCAT_RUNTIME_XACT_TIMED_OUT                   MSGCAT_RUNTIME_NO(11)
#define MSGCAT_RUNTIME_HOSTVAR_INDEX_ERROR              MSGCAT_RUNTIME_NO(12)
#define MSGCAT_RUNTIME_UNIMPLEMENTED_CONV               MSGCAT_RUNTIME_NO(13)
#define MSGCAT_RUNTIME_UNDEFINED_CONVERSION             MSGCAT_RUNTIME_NO(14)
#define MSGCAT_RUNTIME__YIELDS_NO_RESULTS               MSGCAT_RUNTIME_NO(15)
#define MSGCAT_RUNTIME_YIELDS_GT_ONE_ROW                MSGCAT_RUNTIME_NO(16)
#define MSGCAT_RUNTIME_VAR_NOT_DEFINED                  MSGCAT_RUNTIME_NO(17)
#define MSGCAT_RUNTIME__CAN_NOT_EVALUATE                MSGCAT_RUNTIME_NO(18)
#define MSGCAT_RUNTIME_UNKNOWN_VARIABLE                 MSGCAT_RUNTIME_NO(19)
#define MSGCAT_RUNTIME_UNKNOWN_SHARED_ATTR              MSGCAT_RUNTIME_NO(20)
#define MSGCAT_RUNTIME_YIELDS_GT_ONE_COL                MSGCAT_RUNTIME_NO(21)
#define MSGCAT_RUNTIME_NESTED_AGGREGATE                 MSGCAT_RUNTIME_NO(22)
#define MSGCAT_RUNTIME_FUNCTION_NOT_DEFINED             MSGCAT_RUNTIME_NO(23)
#define MSGCAT_RUNTIME_WANT_ONE_COL                     MSGCAT_RUNTIME_NO(24)
#define MSGCAT_RUNTIME_TOO_MANY_VALUES                  MSGCAT_RUNTIME_NO(25)
#define MSGCAT_RUNTIME_VASG_TGT_UNINVERTBL              MSGCAT_RUNTIME_NO(26)
#define MSGCAT_RUNTIME_QSPEC_COLS_GT_ATTRS              MSGCAT_RUNTIME_NO(27)
#define MSGCAT_RUNTIME_ATTRS_GT_QSPEC_COLS              MSGCAT_RUNTIME_NO(28)
#define MSGCAT_RUNTIME_REL_RESTRICTS_AGG_1              MSGCAT_RUNTIME_NO(29)
#define MSGCAT_RUNTIME_REL_RESTRICTS_AGG_2              MSGCAT_RUNTIME_NO(30)
#define MSGCAT_RUNTIME_VC_COMP_NOT_UPDATABL             MSGCAT_RUNTIME_NO(31)
#define MSGCAT_RUNTIME_NO_RELNL_PATH_EXPR               MSGCAT_RUNTIME_NO(32)
#define MSGCAT_RUNTIME_BAD_CONSTR_IN_PATH               MSGCAT_RUNTIME_NO(33)
#define MSGCAT_RUNTIME_PATH_EXPR_CROSSES_DB             MSGCAT_RUNTIME_NO(34)
#define MSGCAT_RUNTIME_PATH_CROSSES_DB_FROM             MSGCAT_RUNTIME_NO(35)
#define MSGCAT_RUNTIME_IS_NOT_AUTHORIZED_ON             MSGCAT_RUNTIME_NO(36)
#define MSGCAT_RUNTIME_SEL_NOT_AUTHORIZED               MSGCAT_RUNTIME_NO(37)
#define MSGCAT_RUNTIME_VCLASS_NOT_UPDATABLE             MSGCAT_RUNTIME_NO(38)
#define MSGCAT_RUNTIME_IS_NOT_A_PROXY                   MSGCAT_RUNTIME_NO(39)
#define MSGCAT_RUNTIME_NO_JOIN_PROXY_QSPEC              MSGCAT_RUNTIME_NO(40)
#define MSGCAT_RUNTIME_NO_OBJECT_ID_SET                 MSGCAT_RUNTIME_NO(41)
#define MSGCAT_RUNTIME_GT_1_OBJ_ID_IN_COMPO             MSGCAT_RUNTIME_NO(42)
#define MSGCAT_RUNTIME_OBJ_ATT_NOT_VCLASS               MSGCAT_RUNTIME_NO(43)
#define MSGCAT_RUNTIME_QSPEC_INCOMP_W_ATTR              MSGCAT_RUNTIME_NO(44)
#define MSGCAT_RUNTIME_CYCLIC_QUERY_SPEC                MSGCAT_RUNTIME_NO(45)
#define MSGCAT_RUNTIME_NO_EXPR_TO_EVALUATE              MSGCAT_RUNTIME_NO(46)
#define MSGCAT_RUNTIME_NO_REALCLASS_4_VCLAS             MSGCAT_RUNTIME_NO(47)
#define MSGCAT_RUNTIME_LDB_QRY_SERVER_ERROR             MSGCAT_RUNTIME_NO(48)
#define MSGCAT_RUNTIME_DBT_PUT_ERROR                    MSGCAT_RUNTIME_NO(49)
#define MSGCAT_RUNTIME_REG_WANT_LDB_NAM                 MSGCAT_RUNTIME_NO(50)
#define MSGCAT_RUNTIME_REG_WANT_NAM_AT_HOST             MSGCAT_RUNTIME_NO(51)
#define MSGCAT_RUNTIME_REG_WRONG_LDB_TYPE               MSGCAT_RUNTIME_NO(52)
#define MSGCAT_RUNTIME_REG_WANT_HOST_NAME               MSGCAT_RUNTIME_NO(53)
#define MSGCAT_RUNTIME_REG_WANT_USER_NAME               MSGCAT_RUNTIME_NO(54)
#define MSGCAT_RUNTIME_REG_WANT_PASSWORD                MSGCAT_RUNTIME_NO(55)
#define MSGCAT_RUNTIME_INSERT_EMPTY    	                MSGCAT_RUNTIME_NO(56)
#define MSGCAT_RUNTIME_UPDATE_EMPTY    	                MSGCAT_RUNTIME_NO(57)
#define MSGCAT_RUNTIME_DELETE_EMPTY    	                MSGCAT_RUNTIME_NO(58)
#define MSGCAT_RUNTIME_INGRES_DATE_LIMIT   	        MSGCAT_RUNTIME_NO(59)
#define MSGCAT_RUNTIME_RESOURCES_EXHAUSTED 	        MSGCAT_RUNTIME_NO(60)
#define MSGCAT_RUNTIME_PARM_IS_NOT_SET 	                MSGCAT_RUNTIME_NO(61)
#define MSGCAT_RUNTIME_LOCAL_CHECK_NOT_IMP 	        MSGCAT_RUNTIME_NO(62)
#define MSGCAT_RUNTIME_CHECK_OPTION_EXCEPT 	        MSGCAT_RUNTIME_NO(63)
#define MSGCAT_RUNTIME_BAD_DATE		                MSGCAT_RUNTIME_NO(64)
#define MSGCAT_RUNTIME_BAD_TIME		                MSGCAT_RUNTIME_NO(65)
#define MSGCAT_RUNTIME_BAD_UTIME		        MSGCAT_RUNTIME_NO(66)
#define MSGCAT_RUNTIME_NO_PROXY_SUBQUERY                MSGCAT_RUNTIME_NO(67)
#define MSGCAT_RUNTIME_LDB_FUNC_CONTRADICT	        MSGCAT_RUNTIME_NO(68)
#define MSGCAT_RUNTIME_BAD_NUMERIC		        MSGCAT_RUNTIME_NO(69)
#define MSGCAT_RUNTIME_OUTER_JOIN_OPT_FAILED            MSGCAT_RUNTIME_NO(70)
#define MSGCAT_RUNTIME_SERIAL_S_SERIAL_I                MSGCAT_RUNTIME_NO(71)
#define MSGCAT_RUNTIME_NO_VID_FOR_NON_UPDATABLE_VIEW    MSGCAT_RUNTIME_NO(72)
#define MSGCAT_RUNTIME_PARTITION_WORK_FAILED            MSGCAT_RUNTIME_NO(73)
#define MSGCAT_RUNTIME_PARTITION_NOT_EXIST              MSGCAT_RUNTIME_NO(74)
#define MSGCAT_RUNTIME_NOT_ALLOWED_ACCESS_TO_PARTITION  MSGCAT_RUNTIME_NO(75)
#define MSGCAT_RUNTIME_RT_SERIAL_NOT_DEFINED            MSGCAT_RUNTIME_NO(76)
#define MSGCAT_RUNTIME_RT_SERIAL_ALTER_NOT_ALLOWED      MSGCAT_RUNTIME_NO(77)
#define MSGCAT_RUNTIME_SERIAL_IS_AUTO_INCREMENT_OBJ     MSGCAT_RUNTIME_NO(78)
#define MSGCAT_RUNTIME_XACT_INVALID_ISO_LVL_MSG         MSGCAT_RUNTIME_NO(79)

#endif /* _PARSER_MESSAGE_H_ */
