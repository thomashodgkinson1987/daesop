#ifndef DAESOP_H
#define DAESOP_H

#include <stdio.h>

#include "resstr.h"
#include "dict.h"

#define NOTHING 0
#define GET_INFORMATION 1
#define GET_RESOURCES_INFORMATION 2
#define GET_OFFSET_INFORMATION 3
#define GET_RESOURCE_INFORMATION_BY_NAME 4
#define GET_RESOURCE_INFORMATION_BY_NUMBER 5
#define GET_RESOURCE_BY_NAME 6
#define GET_RESOURCE_WITH_HEADER_BY_NAME 7
#define GET_RESOURCE_BY_NUMBER 8
#define GET_RESOURCE_WITH_HEADER_BY_NUMBER 9
#define TEST_OLD_BITMAPS 10
#define REPLACE_BY_RESOURCE 11
#define REPLACE_BY_RESOURCE_WITH_HEADER 12
#define CREATE_TBL_FILE 13
#define CONVERT_OLD_BITMAPS 14
#define CONVERT_OLD_BITMAPS_IGNORE_ERRORS 15
#define CONVERT_OLD_FONTS 16
#define CONVERT_OLD_FONTS_IGNORE_ERRORS 17
#define PATCH_EOB3_MENU 18
#define CONVERT_EOB3_TO_AESOP32 19
#define EXTRACT_ALL 20

#define DUMP_LINE_SIZE 16

// sequence of 0 at the end of a TBL file
#define TBL_END_MARKER_LENGTH 36

// syntax
void syntax_information(void);

// Commands
int get_information(
	FILE *res_file,
	DIRPOINTER *directory_pointers,
	char *output_filename);

int get_resource(
	FILE *res_file,
	DIRPOINTER *directory_pointers,
	int function,
	char *resource,
	char *output_filename);

void display_code_resource_information(
	FILE *res_file,
	DIRPOINTER *directory_pointers,
	FILE *output_file,
	int resource_type,
	char *resource_name,
	DICTENTRYPOINTER *resource_name_array);

void display_special_aesop_resource(
	FILE *res_file,
	DIRPOINTER *directory_pointers,
	FILE *output_file,
	int resource_number);

void display_hexadecimal_dump(
	int resource_number,
	FILE *res_file,
	DIRPOINTER *directory_pointers,
	FILE *output_file);

void display_hexadecimal_dump_of_memory_buffer(
	unsigned char *buffer,
	int length,
	FILE *output_file);

int get_resource_information(
	FILE *res_file,
	DIRPOINTER *directory_pointers,
	int function,
	char *resource,
	char *output_filename);

void display_code_resource(
	int code_resource_number,
	char *code_resource_name,
	IMPORTENTRYPOINTER *full_import_resource_dictionary,
	int import_resource_size,
	EXPORTENTRYPOINTER *full_export_resource_dictionary,
	int export_resource_size,
	FILE *res_file,
	DIRPOINTER *directory_pointers,
	FILE *output_file);

int get_resources_information(
	FILE *res_file,
	DIRPOINTER *directory_pointers,
	char *output_filename);

int test_old_bitmaps(
	FILE *res_file,
	DIRPOINTER *directory_pointers,
	char *output_filename);

int replace_resource_by_resource_from_file(
	FILE *res_file,
	DIRPOINTER *directory_pointers,
	char *resource_number_string,
	char *added_resource_fileName,
	char *new_fileName,
	int new_resource_has_header);

int get_offset_information(
	FILE *res_file,
	DIRPOINTER *directory_pointers,
	char *offset_string,
	char *output_filename);

int create_tbl_file(
	FILE *res_file,
	DIRPOINTER *directory_pointers,
	char *tbl_filename);

int convert_old_bitmaps(
	FILE *res_file,
	DIRPOINTER *directory_pointers,
	char *new_fileName,
	int ignore_errors);

int convert_old_fonts(
	FILE *res_file,
	DIRPOINTER *directory_pointers,
	char *new_fileName,
	int ignore_errors);

int patch_eob3_menu(
	FILE *res_file,
	DIRPOINTER *directory_pointers,
	char *new_fileName);

int convert_eob3_to_aesop32(
	FILE *res_file,
	DIRPOINTER *directory_pointers,
	char *new_fileName);

int extract_all_resources(
	FILE *res_file,
	DIRPOINTER *directory_pointers,
	char *output_directory);

#endif
