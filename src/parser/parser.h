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
 * parser.h - Parser module functions
 */

#ifndef _PARSER_H_
#define _PARSER_H_

#ident "$Id$"

#include <stdio.h>
#include <stdarg.h>
#include "dbtype.h"
#include "dbdef.h"
#include "parse_tree.h"

#ifdef __cplusplus
extern "C"
{
#endif

  extern PT_NODE **parser_main (PARSER_CONTEXT * p);
  extern void parser_final (void);

  extern void parser_init_func_vectors (void);

  extern PARSER_CONTEXT *parser_create_parser (void);
  extern void parser_free_parser (PARSER_CONTEXT * parser);

  extern PT_NODE **parser_parse_string (PARSER_CONTEXT * parser,
					const char *buffer);
  extern PT_NODE **parser_parse_binary (PARSER_CONTEXT * parser,
					const char *buffer, size_t size);
  extern PT_NODE **parser_parse_file (PARSER_CONTEXT * parser, FILE * file);

  extern PT_NODE *parser_create_node (const PARSER_CONTEXT * parser);
  extern PT_NODE *parser_new_node (PARSER_CONTEXT * parser,
				   PT_NODE_TYPE node);
  extern PT_NODE *parser_init_node (PT_NODE * node);
  extern void parser_free_node (const PARSER_CONTEXT * parser,
				PT_NODE * node);
  extern void parser_free_tree (PARSER_CONTEXT * parser, PT_NODE * tree);
  extern void parser_free_subtrees (PARSER_CONTEXT * parser, PT_NODE * tree);

  extern PT_NODE *pt_pop (PARSER_CONTEXT * parser);
  extern int pt_push (PARSER_CONTEXT * parser, PT_NODE * q);
  extern PT_NODE *pt_top (PARSER_CONTEXT * parser);

  extern PT_NODE *parser_copy_tree (PARSER_CONTEXT * parser,
				    const PT_NODE * tree);
  extern PT_NODE *parser_copy_tree_list (PARSER_CONTEXT * parser,
					 PT_NODE * tree);
  extern PT_NODE *parser_append_node (PT_NODE * node, PT_NODE * list);
  extern PT_NODE *parser_append_node_or (PT_NODE * node, PT_NODE * list);
  extern PT_NODE *pt_point (PARSER_CONTEXT * parser, const PT_NODE * tree);
  extern PT_NODE *pt_point_l (PARSER_CONTEXT * parser, const PT_NODE * tree);

  extern PT_NODE *parser_walk_leaves (PARSER_CONTEXT * parser,
				      PT_NODE * node,
				      PT_NODE_WALK_FUNCTION pre_function,
				      void *pre_argument,
				      PT_NODE_WALK_FUNCTION post_function,
				      void *post_argument);
  extern PT_NODE *parser_walk_tree (PARSER_CONTEXT * parser,
				    PT_NODE * node,
				    PT_NODE_WALK_FUNCTION pre_function,
				    void *pre_argument,
				    PT_NODE_WALK_FUNCTION post_function,
				    void *post_argument);
  extern PT_NODE *pt_continue_walk (PARSER_CONTEXT * parser, PT_NODE * tree,
				    void *arg, int *continue_walk);

  extern char *parser_print_tree (PARSER_CONTEXT * parser,
				  const PT_NODE * node);
  extern char *parser_print_tree_list (PARSER_CONTEXT * parser,
				       const PT_NODE * p);
  extern char *pt_print_alias (PARSER_CONTEXT * parser, const PT_NODE * node);
  extern char *pt_short_print (PARSER_CONTEXT * parser, const PT_NODE * p);
  extern char *pt_short_print_l (PARSER_CONTEXT * parser, const PT_NODE * p);

  extern void *parser_alloc (const PARSER_CONTEXT * parser, const int length);
  extern char *pt_append_string (const PARSER_CONTEXT * parser,
				 char *old_string, const char *new_tail);

  extern PARSER_VARCHAR *pt_append_bytes (const PARSER_CONTEXT * parser,
					  PARSER_VARCHAR * old_bytes,
					  const char *new_tail,
					  const int length);
  extern PARSER_VARCHAR *pt_append_varchar (const PARSER_CONTEXT * parser,
					    PARSER_VARCHAR * old_bytes,
					    const PARSER_VARCHAR * new_tail);
  extern PARSER_VARCHAR *pt_append_nulstring (const PARSER_CONTEXT * parser,
					      PARSER_VARCHAR * old_bytes,
					      const char *new_tail);
  extern PARSER_VARCHAR *pt_append_name (const PARSER_CONTEXT * parser,
					 PARSER_VARCHAR * string,
					 const char *name);
  extern const unsigned char *pt_get_varchar_bytes (const PARSER_VARCHAR *
						    string);
  extern int pt_get_varchar_length (const PARSER_VARCHAR * string);

  extern PARSER_VARCHAR *pt_print_bytes (PARSER_CONTEXT * parser,
					 const PT_NODE * node);
  extern PARSER_VARCHAR *pt_print_bytes_l (PARSER_CONTEXT * parser,
					   const PT_NODE * node);
  extern PARSER_VARCHAR *pt_print_bytes_spec_list (PARSER_CONTEXT * parser,
						   const PT_NODE * node);
  extern PARSER_VARCHAR *pt_print_class_name (PARSER_CONTEXT * parser,
					      PT_NODE * p);
  extern PARSER_VARCHAR *pt_print_and_list (PARSER_CONTEXT * parser,
					    const PT_NODE * node);
  extern PARSER_VARCHAR *pt_print_bytes_alias (PARSER_CONTEXT * parser,
					       const PT_NODE * node);

  extern char *pt_print_query_spec_no_list (PARSER_CONTEXT * parser,
					    const PT_NODE * node);

  extern PT_NODE *pt_compile (PARSER_CONTEXT * parser, PT_NODE * statement);

  extern PT_NODE *pt_semantic_type (PARSER_CONTEXT * parser, PT_NODE * tree,
				    SEMANTIC_CHK_INFO * sc_info);

  extern void pt_report_to_ersys (const PARSER_CONTEXT * parser,
				  const PT_ERROR_TYPE error_type);

  extern void pt_record_error (PARSER_CONTEXT * parser, int stmt_no,
			       int line_no, int col_no, const char *msg);

  extern void pt_frob_warning (PARSER_CONTEXT * parser,
			       const PT_NODE * statement, const char *fmt,
			       ...);

  extern void pt_frob_error (PARSER_CONTEXT * parser,
			     const PT_NODE * statement, const char *fmt, ...);

  extern void pt_end_query (PARSER_CONTEXT * parser);

  extern void pt_set_host_variables (PARSER_CONTEXT * parser,
				     int count, DB_VALUE * values);
  extern DB_VALUE *pt_host_var_db_value (PARSER_CONTEXT * parser,
					 PT_NODE * hv);
  extern PT_NODE *pt_bind_values_to_hostvars (PARSER_CONTEXT * parser,
					      PT_NODE * node);

  extern int pt_length_of_list (PT_NODE * list);
  extern int pt_length_of_select_list (PT_NODE * list, int hidden_col);

  extern PT_NODE *pt_get_select_list (PARSER_CONTEXT * parser,
				      PT_NODE * query);

  extern int pt_associate_label_with_value (const char *label,
					    DB_VALUE * val);
  extern DB_VALUE *pt_find_value_of_label (const char *label);
  extern int pt_find_labels (DB_NAMELIST ** list);
  extern void pt_free_label_table (void);

  extern bool pt_is_reserved_word (const char *s);
  extern bool pt_is_keyword (const char *s);
  extern bool pt_is_const_expr_node (PT_NODE * node);

  extern PT_NODE *pt_add_row_oid (PARSER_CONTEXT * parser, PT_NODE * stmt);
  extern PT_NODE *pt_add_row_oid_name (PARSER_CONTEXT * parser,
				       PT_NODE * stmt);
  extern PT_NODE *pt_add_column_oid (PARSER_CONTEXT * parser, PT_NODE * stmt);
  extern PT_NODE *pt_add_row_classoid_name (PARSER_CONTEXT * parser,
					    PT_NODE * statement,
					    int server_op);

  extern PT_NODE *pt_class_pre_fetch (PARSER_CONTEXT * parser,
				      PT_NODE * statement);

  extern PT_NODE *pt_compile_trigger_stmt (PARSER_CONTEXT * parser,
					   const char *trigger_stmt,
					   DB_OBJECT * class_op,
					   const char *name1,
					   const char *name2);
  extern int pt_exec_trigger_stmt (PARSER_CONTEXT * parser,
				   PT_NODE * trigger_stmt,
				   DB_OBJECT * object1,
				   DB_OBJECT * object2, DB_VALUE * result);

  extern DB_TYPE pt_type_enum_to_db (const PT_TYPE_ENUM dt);
  extern PT_TYPE_ENUM pt_db_to_type_enum (const DB_TYPE t);
  extern PT_TYPE_ENUM pt_get_type_enum (PT_NODE * node);
  extern const char *pt_type_enum_to_db_domain_name (const PT_TYPE_ENUM t);
  extern DB_DOMAIN *pt_type_enum_to_db_domain (const PT_TYPE_ENUM t);
  extern void pt_put_type_enum (PARSER_CONTEXT * parser,
				PT_NODE * node, PT_NODE * data_type);
  extern const char *pt_data_type_to_db_domain_name (const PT_NODE * dt);
  extern DB_DOMAIN *pt_data_type_to_db_domain (PARSER_CONTEXT * parser,
					       PT_NODE * dt,
					       const char *class_name);
  extern DB_DOMAIN *pt_node_data_type_to_db_domain (PARSER_CONTEXT * parser,
						    PT_NODE * dt,
						    PT_TYPE_ENUM type);
  extern const char *pt_node_to_db_domain_name (PT_NODE * node);
  extern DB_DOMAIN *pt_node_to_db_domain (PARSER_CONTEXT * parser,
					  PT_NODE * node,
					  const char *class_name);
  extern DB_TYPE pt_node_to_db_type (PT_NODE * node);

  extern PT_NODE *pt_dbval_to_value (PARSER_CONTEXT * parser,
				     const DB_VALUE * val);
  extern DB_VALUE *pt_seq_value_to_db (PARSER_CONTEXT * parser,
				       PT_NODE * values, DB_VALUE * db_value,
				       PT_NODE ** el_types);
  extern DB_VALUE *pt_set_value_to_db (PARSER_CONTEXT * parser,
				       PT_NODE ** values, DB_VALUE * db_value,
				       PT_NODE ** el_types);
  extern DB_AUTH pt_auth_to_db_auth (const PT_NODE * auth);
  extern DB_DOMAIN *pt_string_to_db_domain (const char *s,
					    const char *class_name);

  extern DB_VALUE *pt_value_to_db (PARSER_CONTEXT * parser, PT_NODE * value);

  extern int pt_coerce_value (PARSER_CONTEXT * parser,
			      PT_NODE * src,
			      PT_NODE * dest,
			      PT_TYPE_ENUM desired_type,
			      PT_NODE * elem_type_list);
  PT_NODE *pt_wrap_with_cast_op (PARSER_CONTEXT * parser, PT_NODE * arg,
				 PT_TYPE_ENUM new_type, int p, int s);

  extern PT_NODE *pt_bind_type_from_dbval (PARSER_CONTEXT *, PT_NODE *,
					   DB_VALUE *);

  extern PT_NODE *pt_cnf (PARSER_CONTEXT * parser, PT_NODE * node);

  extern PT_NODE *pt_sort_in_desc_order (PT_NODE * vlist);

  extern void pt_add_type_to_set (PARSER_CONTEXT * parser,
				  const PT_NODE * val, PT_NODE ** set);

  extern PT_OP_TYPE pt_converse_op (PT_OP_TYPE op);
  extern int pt_is_between_range_op (PT_OP_TYPE op);
  extern int pt_is_comp_op (PT_OP_TYPE op);
  extern PT_OP_TYPE pt_negate_op (PT_OP_TYPE op);
  extern int pt_comp_to_between_op (PT_OP_TYPE left, PT_OP_TYPE right,
				    PT_COMP_TO_BETWEEN_OP_CODE_TYPE code,
				    PT_OP_TYPE * between);
  extern int pt_between_to_comp_op (PT_OP_TYPE between,
				    PT_OP_TYPE * left, PT_OP_TYPE * right);

  extern PT_NODE *pt_eval_value_path (PARSER_CONTEXT * parser,
				      PT_NODE * path);
  extern bool pt_eval_path_expr (PARSER_CONTEXT * parser, PT_NODE * tree,
				 DB_VALUE * val);
  extern void pt_evaluate_tree (PARSER_CONTEXT * parser, PT_NODE * tree,
				DB_VALUE * db_value);
  extern void pt_evaluate_tree_having_serial (PARSER_CONTEXT * parser,
					      PT_NODE * tree,
					      DB_VALUE * db_value);
  extern int pt_evaluate_db_value_expr (PARSER_CONTEXT * parser,
					PT_OP_TYPE op, DB_VALUE * arg1,
					DB_VALUE * arg2, DB_VALUE * arg3,
					DB_VALUE * result, TP_DOMAIN * domain,
					PT_NODE * o1, PT_NODE * o2,
					PT_NODE * o3, PT_MISC_TYPE qualifier);

  extern bool pt_is_symmetric_op (PT_OP_TYPE op);

  extern void mq_free_virtual_query_cache (PARSER_CONTEXT * parser);
  extern PARSER_CONTEXT *mq_virtual_queries (DB_OBJECT * class_obj);

  extern int pt_node_to_cmd_type (PT_NODE * node);

  extern int pt_check_if_query (PARSER_CONTEXT * parser, PT_NODE * stmt);

  extern PT_NODE *pt_count_input_markers (PARSER_CONTEXT * parser,
					  PT_NODE * node, void *arg,
					  int *continue_walk);
  extern PT_NODE *pt_count_output_markers (PARSER_CONTEXT * parser,
					   PT_NODE * node, void *arg,
					   int *continue_walk);

  extern PT_NODE *pt_has_using_index_clause (PARSER_CONTEXT * parser,
					     PT_NODE * node, void *arg,
					     int *continue_walk);

  extern PT_NODE *meth_translate (PARSER_CONTEXT * parser, PT_NODE * node);

  extern const char *pt_show_partition_type (PT_PARTITION_TYPE t);

  extern UINTPTR pt_find_id (PARSER_CONTEXT * parser, PT_NODE * node,
			     UINTPTR id);

  extern int pt_identifier_or_keyword (const char *text);
  extern KEYWORD_RECORD *pt_get_keyword_rec (int *rec_count);
  extern int pt_type_generic_func (PARSER_CONTEXT * parser, PT_NODE * node);
  extern void pt_string_to_data_type (PARSER_CONTEXT * parser, const char *s,
				      PT_NODE * node);

  extern const char *pt_show_alter (PT_ALTER_CODE c);
  extern const char *pt_show_binopcode (PT_OP_TYPE n);	/* printable opcode */
  extern const char *pt_show_type_enum (PT_TYPE_ENUM t);
  extern const char *pt_show_function (FUNC_TYPE c);
  extern const char *pt_show_misc_type (PT_MISC_TYPE p);	/* return  misc_type */
  extern const char *pt_show_node_type (PT_NODE * p);	/*return node_type */
  extern const char *pt_show_oid_type (DB_OBJECT_ID_TYPE t);
  extern const char *pt_show_priv (PT_PRIV_TYPE t);

  extern PT_NODE *pt_lambda_with_arg (PARSER_CONTEXT * parser_ptr,
				      PT_NODE * expression,
				      PT_NODE * name,
				      PT_NODE * named_expression,
				      bool loc_check,
				      int type, bool dont_replace);
  extern PT_NODE *pt_lambda (PARSER_CONTEXT * parser_ptr,
			     PT_NODE * expression,
			     PT_NODE * name, PT_NODE * named_expression);

  extern const char *pt_in_same_ldb (PARSER_CONTEXT * parser, PT_NODE * node,
				     PT_NODE * spec);

  extern PT_NODE *pt_resolve_names (PARSER_CONTEXT * parser,
				    PT_NODE * statement,
				    SEMANTIC_CHK_INFO * sc_info);

  extern PT_NODE *pt_resolve_using_index (PARSER_CONTEXT * parser,
					  PT_NODE * index, PT_NODE * from);

  extern int pt_get_correlation_level (PT_NODE * node);

  extern PT_NODE *pt_get_subquery_list (PT_NODE * node);
  extern int pt_get_expression_number (PT_NODE * node);
  extern void pt_select_list_to_one_col (PARSER_CONTEXT * parser,
					 PT_NODE * node, bool do_one);
  extern PT_NODE *pt_rewrite_set_eq_set (PARSER_CONTEXT * parser,
					 PT_NODE * exp);
  extern int pt_null_where (PARSER_CONTEXT * parser, PT_NODE * node);
  extern PT_TYPE_ENUM pt_common_type (PT_TYPE_ENUM arg1_type,
				      PT_TYPE_ENUM arg2_type);

  extern int pt_get_one_tuple_from_list_id (PARSER_CONTEXT * parser,
					    PT_NODE * tree,
					    struct db_value *vals, int cnt);

  extern PT_NODE *pt_add_class_to_entity_list (PARSER_CONTEXT * r,
					       struct db_object *db,
					       PT_NODE * entity,
					       const PT_NODE * parent,
					       UINTPTR id,
					       PT_MISC_TYPE meta_class);

  extern int pt_check_same_datatype (const PARSER_CONTEXT * parser,
				     const PT_NODE * p, const PT_NODE * q);

  extern PT_NODE *pt_gather_constraints (PARSER_CONTEXT * parser,
					 PT_NODE * tree);
  extern int pt_check_set_count_set (PARSER_CONTEXT * parser, PT_NODE * arg1,
				     PT_NODE * arg2);
  extern int pt_get_expression_count (PT_NODE * node);

  extern int pt_validate_query_spec (PARSER_CONTEXT * parser,
				     PT_NODE * s, struct db_object *c);
  extern PT_NODE *mq_regenerate_if_ambiguous (PARSER_CONTEXT * parser,
					      PT_NODE * spec,
					      PT_NODE * statement,
					      PT_NODE * from);
  extern void pt_evaluate_tree_internal (PARSER_CONTEXT * parser,
					 PT_NODE * tree,
					 DB_VALUE * db_value,
					 bool set_insert);
  extern void pt_evaluate_tree_having_serial_internal (PARSER_CONTEXT *
						       parser, PT_NODE * tree,
						       DB_VALUE * db_value,
						       bool set_insert);
  extern PT_NODE *pt_do_cnf (PARSER_CONTEXT * parser, PT_NODE * node,
			     void *arg, int *continue_walk);
  extern PT_NODE *pt_find_entity (PARSER_CONTEXT * parser,
				  const PT_NODE * scope, UINTPTR id);
  extern int pt_find_var (PT_NODE * p, PT_NODE ** result);
  extern PT_NODE *pt_dump (PT_NODE * node);
  extern MISC_OPERAND pt_misc_to_qp_misc_operand (PT_MISC_TYPE
						  misc_specifier);
  extern void pt_report_to_ersys_with_statement (PARSER_CONTEXT * parser,
						 const PT_ERROR_TYPE
						 error_type,
						 PT_NODE * statement);
  extern PT_NODE **pt_init_one_statement_parser (PARSER_CONTEXT * parser,
						 FILE * file);

  extern void pt_resolve_object (PARSER_CONTEXT * parser, PT_NODE * node);
  extern int pt_resolved (const PT_NODE * expr);
  extern bool pt_false_where (PARSER_CONTEXT * parser, PT_NODE * statement);
  extern PT_NODE *pt_where_type (PARSER_CONTEXT * parser, PT_NODE * where);
  extern bool pt_false_search_condition (PARSER_CONTEXT * parser,
					 const PT_NODE * statement);
  extern const char *mq_generate_name (PARSER_CONTEXT * parser,
				       const char *root, int *version);
  extern int mq_is_real_class_of_vclass (PARSER_CONTEXT * parser,
					 const PT_NODE * s_class,
					 const PT_NODE * d_class);
  extern void pt_no_double_updates (PARSER_CONTEXT * parser, PT_NODE * stmt);
  extern void *pt_internal_error (PARSER_CONTEXT * parser, const char *file,
				  int line, const char *what);
  extern void pt_void_internal_error (PARSER_CONTEXT * parser,
				      const char *file, int line,
				      const char *what);

  extern DB_OBJECT *pt_check_user_owns_class (PARSER_CONTEXT * parser,
					      PT_NODE * cls_ref);
  extern PT_NODE *pt_domain_to_data_type (PARSER_CONTEXT * parser,
					  DB_DOMAIN * domain);
  extern PT_NODE *pt_flat_spec_pre (PARSER_CONTEXT * parser, PT_NODE * p,
				    void *scope, int *continue_walk);
  extern DB_QUERY_RESULT *pt_new_query_result_descriptor (PARSER_CONTEXT *
							  parser,
							  PT_NODE * query);
  extern DB_QUERY_RESULT *pt_make_cache_hit_result_descriptor (void);
  extern PT_NODE *pt_remove_from_list (PARSER_CONTEXT * parser,
				       PT_NODE * node, PT_NODE * list);
  extern int pt_check_path_eq (PARSER_CONTEXT * parser, PT_NODE * p,
			       PT_NODE * q);
  extern int pt_check_class_eq (PARSER_CONTEXT * parser, PT_NODE * p,
				PT_NODE * q);

  extern DB_QUERY_TYPE *pt_get_titles (PARSER_CONTEXT * parser,
				       PT_NODE * query);
  extern DB_QUERY_TYPE *pt_fillin_type_size (PARSER_CONTEXT * parser,
					     PT_NODE * query,
					     DB_QUERY_TYPE * list,
					     const int include_oid);
  extern void pt_free_query_etc_area (PT_NODE * query);
  DB_OBJECT *pt_find_users_class (PARSER_CONTEXT * parser, PT_NODE * name);
  DB_ATTRIBUTE *db_get_attribute_force (DB_OBJECT * obj, const char *name);
  DB_ATTRIBUTE *db_get_attributes_force (DB_OBJECT * obj);

  extern PT_NODE *pt_set_is_view_spec (PARSER_CONTEXT * parser,
				       PT_NODE * node, void *dummy,
				       int *continue_walk);

  extern PT_NODE *pt_resolve_star (PARSER_CONTEXT * parser, PT_NODE * from,
				   PT_NODE * attr);

  extern PT_NODE *pt_bind_param_node (PARSER_CONTEXT * parser, PT_NODE * node,
				      void *arg, int *continue_walk);
  extern int pt_statement_have_methods (PARSER_CONTEXT * parser,
					PT_NODE * statement);
  extern int pt_streq (const char *p, const char *q);

  extern void pt_to_regu_resolve_domain (int *p_precision, int *p_scale,
					 const PT_NODE * node);
  extern PT_NODE *pt_make_prim_data_type_fortonum (PARSER_CONTEXT * parser,
						   int prec, int scale);
  extern PT_NODE *pt_make_prim_data_type (PARSER_CONTEXT * parser,
					  PT_TYPE_ENUM e);

  extern int pt_find_attribute (PARSER_CONTEXT * parser,
				const PT_NODE * name,
				const PT_NODE * attributes);

  extern PT_NODE *pt_and (PARSER_CONTEXT * parser_ptr,
			  const PT_NODE * expression1,
			  const PT_NODE * expression2);
  extern PT_NODE *pt_union (PARSER_CONTEXT * parser_ptr,
			    PT_NODE * expression1, PT_NODE * expression2);
  extern PT_NODE *pt_name (PARSER_CONTEXT * parser_ptr, const char *name);
  extern PT_NODE *pt_entity (PARSER_CONTEXT * parser,
			     const PT_NODE * entity_name,
			     const PT_NODE * range_var,
			     const PT_NODE * flat_list);
  extern bool pt_name_equal (PARSER_CONTEXT * parser_ptr,
			     const PT_NODE * name1, const PT_NODE * name2);
  extern PT_NODE *pt_find_name (PARSER_CONTEXT * parser, const PT_NODE * name,
				const PT_NODE * list);
  extern bool pt_is_aggregate_function (PARSER_CONTEXT * parser,
					const PT_NODE * node);
  extern PT_NODE *pt_find_spec (PARSER_CONTEXT * parser, const PT_NODE * from,
				const PT_NODE * name);
  extern PT_NODE *pt_find_spec_pre (PARSER_CONTEXT * parser, PT_NODE * node,
				    void *arg, int *continue_walk);
  extern PT_NODE *pt_find_spec_post (PARSER_CONTEXT * parser, PT_NODE * node,
				     void *arg, int *continue_walk);
  extern PT_NODE *pt_is_aggregate_node (PARSER_CONTEXT * parser,
					PT_NODE * tree, void *arg,
					int *continue_walk);
  extern PT_NODE *pt_is_aggregate_node_post (PARSER_CONTEXT * parser,
					     PT_NODE * tree, void *arg,
					     int *continue_walk);
  extern int pt_is_ddl_statement (const PT_NODE * node);
  extern int pt_is_method_call (PT_NODE * node);
  extern int pt_is_attr (PT_NODE * node);

  extern int pt_instnum_compatibility (PT_NODE * expr);
  extern int pt_groupbynum_compatibility (PT_NODE * expr);
  extern PT_NODE *pt_check_instnum_pre (PARSER_CONTEXT * parser,
					PT_NODE * node, void *arg,
					int *continue_walk);
  extern PT_NODE *pt_check_instnum_post (PARSER_CONTEXT * parser,
					 PT_NODE * node, void *arg,
					 int *continue_walk);
  extern PT_NODE *pt_check_groupbynum_pre (PARSER_CONTEXT * parser,
					   PT_NODE * node, void *arg,
					   int *continue_walk);
  extern PT_NODE *pt_check_groupbynum_post (PARSER_CONTEXT * parser,
					    PT_NODE * node, void *arg,
					    int *continue_walk);
  extern PT_NODE *pt_check_orderbynum_pre (PARSER_CONTEXT * parser,
					   PT_NODE * node, void *arg,
					   int *continue_walk);
  extern PT_NODE *pt_check_orderbynum_post (PARSER_CONTEXT * parser,
					    PT_NODE * node, void *arg,
					    int *continue_walk);

  extern PT_NODE *pt_assignments_part (const PT_NODE * update_statement);
  extern PT_NODE *pt_attrs_part (const PT_NODE * insert_statement);
  extern PT_NODE *pt_class_names_part (const PT_NODE * stmt);
  extern PT_NODE *pt_left_part (const PT_NODE * expr);
  extern PT_NODE *pt_arg1_part (const PT_NODE * node);
  extern PT_NODE *pt_arg2_part (const PT_NODE * node);
  extern PT_NODE *pt_from_list_part (const PT_NODE * node);
  extern PT_NODE *pt_order_by_part (const PT_NODE * node);
  extern PT_NODE *pt_group_by_part (const PT_NODE * node);
  extern PT_NODE *pt_having_part (const PT_NODE * node);
  extern PT_NODE *pt_from_entity_part (const PT_NODE * node);
  extern PT_NODE *pt_class_part (const PT_NODE * statement);
  extern void *pt_object_part (const PT_NODE * name_node);
  extern int pt_operator_part (const PT_NODE * expr);
  extern const char *pt_qualifier_part (const PT_NODE * tbl);
  extern PT_NODE *pt_right_part (const PT_NODE * expr);
  extern PT_NODE *pt_select_list_part (const PT_NODE * stmt);
  extern const char *pt_string_part (const PT_NODE * tbl);
  extern PT_NODE *pt_values_part (const PT_NODE * insert_statement);
  extern PT_NODE *pt_where_part (const PT_NODE * stmt);

  extern void pt_set_node_etc (PT_NODE * node, const void *etc);
  extern void pt_null_etc (PT_NODE * node);
  extern void *pt_node_etc (const PT_NODE * col);
  extern PT_NODE *pt_node_next (const PT_NODE * node);


  extern void pt_record_warning (PARSER_CONTEXT * parser, int stmt_no,
				 int line_no, int col_no, const char *msg);
  extern PT_NODE *pt_get_warnings (const PARSER_CONTEXT * parser);
  extern PT_NODE *pt_get_errors (PARSER_CONTEXT * parser);

  extern PT_NODE *pt_get_next_error (PT_NODE *
				     errors, int *stmt_no,
				     int *line_no, int *col_no,
				     const char **msg);
  extern void pt_reset_error (PARSER_CONTEXT * parser);
  extern int pt_has_error (const PARSER_CONTEXT * parser);

  extern bool pt_column_updatable (PARSER_CONTEXT * parser, PT_NODE * query);

  extern int pt_statement_line_number (const PT_NODE * stmt);

  extern const char *pt_get_select_from_name (PARSER_CONTEXT * parser,
					      const PT_NODE * spec);
  extern const char *pt_get_proxy_spec_name (const char *qspec);
  extern const char *pt_get_spec_name (PARSER_CONTEXT * parser,
				       const PT_NODE * selqry);
  extern const char *pt_get_name (PT_NODE * nam);
  extern PT_NODE *pt_get_cursor (const PT_HOST_VARS * hv);
  extern PT_NODE *pt_get_parameters (PARSER_CONTEXT * parser,
				     PT_NODE * statement);

  extern bool pt_has_aggregate (PARSER_CONTEXT * parser, PT_NODE * node);

  extern int pt_host_var_index (const PT_NODE * hv);
  extern PT_NODE *pt_get_input_host_vars (const PT_HOST_VARS * hv);
  extern PT_NODE *pt_get_output_host_descr (PT_HOST_VARS * hv);
  extern PT_NODE *pt_get_output_host_vars (const PT_HOST_VARS * hv);
  extern PT_HOST_VARS *pt_host_info (PARSER_CONTEXT * parser, PT_NODE * stmt);
  extern void pt_free_host_info (PT_HOST_VARS * hv);

  extern void pt_set_update_object (PARSER_CONTEXT * parser, PT_NODE * node);

  extern char *pt_chop_trailing_dots (PARSER_CONTEXT * parser,
				      const char *msg);

  extern void pt_register_orphan (PARSER_CONTEXT * parser,
				  const PT_NODE * orphan);
  extern void pt_register_orphan_db_value (PARSER_CONTEXT * parser,
					   const DB_VALUE * orphan);
  extern void pt_free_orphans (PARSER_CONTEXT * parser);

  extern bool pt_sort_spec_cover (PT_NODE * cur_list, PT_NODE * new_list);

  extern int dbcs_get_next (PARSER_CONTEXT * parser);
  extern void dbcs_start_input (void);

  extern void parser_free_lcks_classes (PARSER_CONTEXT * parser);

#ifdef __cplusplus
}
#endif

#endif				/* _PARSER_H_ */
