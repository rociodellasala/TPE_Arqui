#ifndef VSA_DRIVER_H
#define VSA_DRIVER_H

/* Starts the video mode configuration. Loads the screen memory pointer in the drivers */
void  start_video_mode();

/* Deletes a line on the screen */
void deleteLine(int line);

/* Draws a pixel in the indicated coordinates */
void draw_pixel(int x, int y);

/* Draws a Character in the indicated coordinates */
void draw_char(unsigned char c, int x, int y);

/* Draws a String in the indicated coordinates */
void draw_string( char * str , int x , int y);

/* Draws a filled rectangle from two points, the lower right and the upper right.
 * NOTE: the coordinates of the first point (x1, y1) are always lower than the ones
 * of the second point.(x2, y2) If not, the rectangle will not be drawn */
void draw_filled_rectangle(int x1, int y1, int x2, int y2, int color);

/*  Blackens the screen and resets the writing position */
void clear_screen();

/* Writes a character in the next writing position. */
void print_char(unsigned char c);

/* Prints a String in the next writing position */
void print_string(const char * str);

/* Prints a String until the indicated length */
void print_string_by_length(const char * str, int length);

/* Deletes the character in the previous writing position */
void delete();

/* Ends the line and continue drawing characters in the bottom line */
void nextLine();

/* Changes current font color acording to parameter */
void changeFontColor(int color);

#endif
