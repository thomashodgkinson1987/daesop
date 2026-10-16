#ifndef CONVERT_H
#define CONVERT_H

#include <stdio.h>

// leave reserve for future
#define MAX_BITMAP_WIDTH 2500
#define MAX_BITMAP_HEIGHT 2500

// font limits
#define MAX_FONT_HEIGHT 50
#define MAX_CHARACTERS_IN_OLD_FONT 256

// new bitmap constants (see "VFX shape File" documentation in VFX library)
#define MAX_NEW_RUN_LENGTH 127
#define MAX_NEW_STRING_LENGTH 127
#define MAX_NEW_SKIP_LENGTH 255

// new bitmap structures
struct NEW_BITMAP_GLOBAL_HEADER
{
	char version1;
	char version2;
	char version3;
	char version4;
	int number_of_shapes;
};

struct NEW_BITMAP_SUBPICTURE_HEADER
{
	unsigned short boundsy;
	unsigned short boundsx;
	unsigned short originy;
	unsigned short originx;
	int xmin;
	int ymin;
	int xmax;
	int ymax;
};

// TODO: The old font header is almost certainly incomplete, fix it!
struct OLD_FONT_HEADER
{
	unsigned short char_count;
	unsigned short char_height;
	unsigned char header4;
	unsigned char header5;
	unsigned char header6;
	unsigned char header7;
};

// new font header
struct NEW_FONT_HEADER
{
	unsigned char version1;
	unsigned char version2;
	unsigned char version3;
	unsigned char version4;
	unsigned int char_count;
	unsigned int char_height;
	unsigned int font_background;
};

// bitmap testing
int test_one_old_bitmap(
	FILE *res_file,
	DIRPOINTER *directory_pointers,
	char *bitmap_name,
	int bitmap_number,
	FILE *output_file);

// replacement of resources
int replace_resource_by_resource_from_memory(
	FILE *res_file,
	char *resource_name,
	int resource_number,
	unsigned char *added_resource_buffer,
	unsigned int added_resource_size,
	char *new_filename,
	int new_resource_has_header);

int replace_resource_in_opened_file(
	char *resource_name,
	int resource_number,
	unsigned char *added_resource_buffer,
	unsigned int added_resource_size,
	FILE *new_file,
	struct RESGlobalHeader *new_file_header,
	DIRPOINTER *new_file_directory_pointers,
	int new_resource_has_header);

// conversion of bitmaps
int convert_one_old_bitmap(
	FILE *new_file,
	DIRPOINTER *new_file_directory_pointers,
	struct RESGlobalHeader *new_file_header,
	int resource_number,
	char *resource_name);

unsigned char *get_new_bitmap_for_old_bitmap(
	unsigned char *old_resource_buffer,
	unsigned int old_resource_length,
	int *new_resource_length);

unsigned char *allocate_new_bitmap_buffer(
	int old_bitmap_header_size,
	int *new_bitmap_buffer_length);

int prepare_new_bitmap_global_header(
	unsigned char *new_bitmap_buffer,
	int new_bitmap_buffer_length,
	int *new_bitmap_buffer_pointer,
	int subpictures);

void store_new_bitmap_subpicture_pointer(
	unsigned char *new_bitmap_buffer,
	int index,
	unsigned int pointer);

int prepare_new_bitmap_subpicture_header(
	unsigned char *new_bitmap_buffer,
	int new_bitmap_buffer_length,
	int *new_bitmap_buffer_pointer,
	int width,
	int height);

int convert_one_old_subpicture(
	unsigned char *old_resource_buffer,
	int old_resource_buffer_length,
	unsigned int old_picture_start,
	unsigned char *new_bitmap_buffer,
	int new_bitmap_buffer_length,
	int *new_bitmap_buffer_pointer);

int generate_skip_sequences_and_empty_lines(
	int *future_position_x,
	int *future_position_y,
	int old_x,
	int old_y,
	unsigned char *new_bitmap_buffer,
	int new_bitmap_buffer_length,
	int *new_bitmap_buffer_pointer);

int process_old_subpicture_copy_sequence(
	int old_x,
	int old_y,
	unsigned char *old_resource_buffer,
	int old_resource_buffer_length,
	int pos,
	int amount,
	unsigned char *new_bitmap_buffer,
	int new_bitmap_buffer_length,
	int *new_bitmap_buffer_pointer,
	int *future_position_x,
	int *future_position_y);

int process_old_subpicture_fill_sequence(
	int old_x,
	int old_y,
	unsigned char *old_resource_buffer,
	int old_resource_buffer_length,
	char value,
	int amount,
	unsigned char *new_bitmap_buffer,
	int new_bitmap_buffer_length,
	int *new_bitmap_buffer_pointer,
	int *future_position_x,
	int *future_position_y);

int add_new_end_token(
	unsigned char *new_bitmap_buffer,
	int new_bitmap_buffer_length,
	int *new_bitmap_buffer_pointer,
	int *future_position_x,
	int *future_position_y);

int add_new_skip_token(
	unsigned char *new_bitmap_buffer,
	int new_bitmap_buffer_length,
	int *new_bitmap_buffer_pointer,
	int length,
	int *future_position_x);

int add_new_string_token(
	unsigned char *old_resource_buffer,
	int old_resource_buffer_length,
	int pos,
	int amount,
	unsigned char *new_bitmap_buffer,
	int new_bitmap_buffer_length,
	int *new_bitmap_buffer_pointer,
	int *future_position_x);

int add_new_run_token(
	unsigned char value,
	int amount,
	unsigned char *new_bitmap_buffer,
	int new_bitmap_buffer_length,
	int *new_bitmap_buffer_pointer,
	int *future_position_x);

// conversion of fonts
int convert_one_old_font(
	FILE *new_file,
	DIRPOINTER *new_file_directory_pointers,
	struct RESGlobalHeader *new_file_header,
	int resource_number,
	char *resource_name);

unsigned char *allocate_new_font_buffer(
	unsigned int old_font_header_size,
	unsigned int *new_font_buffer_length);

void free_old_character_definition_table(
	unsigned char **old_character_definition_table);

unsigned char *get_new_font_for_old_font(
	unsigned char *old_resource_buffer,
	unsigned int old_resource_length,
	int *new_resource_length);

int read_old_character_definition(
	unsigned char **result,
	int start_pos,
	int character,
	unsigned char *old_resource_buffer,
	unsigned int old_resource_length,
	int height);

int prepare_new_font_header(
	int number_of_characters,
	int font_height,
	unsigned char *new_font_buffer,
	unsigned int new_font_buffer_length,
	int *new_font_buffer_pointer);

int convert_old_and_store_new_character(
	unsigned char *old_character_definition,
	int character,
	int font_height,
	unsigned char *new_font_buffer,
	unsigned int new_font_buffer_length,
	int *new_font_buffer_pointer,
	int new_offsets_start);

int patch_eob3_menu_in_opened_file(
	FILE *new_file,
	DIRPOINTER *new_file_directory_pointers,
	struct RESGlobalHeader *new_file_header);

int patch_eob3_menu_alignment_in_opened_file(
	FILE *new_file,
	DIRPOINTER *new_file_directory_pointers,
	struct RESGlobalHeader *new_file_header);

int patch_one_byte(
	unsigned char *binary,
	int binary_length,
	int address,
	unsigned char old_value,
	unsigned char new_value);

#endif
