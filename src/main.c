#include <cairo/cairo.h>
#include <math.h>
#include <stdio.h>

void create_frame(int i) {
  char filename[100];
  sprintf(filename, "build/frame-%03d.png", i);

  cairo_surface_t *surface =
      cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 340, 180);
  cairo_t *cr = cairo_create(surface);

  cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);
  cairo_paint(cr);

  cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);
  cairo_arc(cr, 170 + 30 * sin(i / 32.0 * 2 * 3.14159), 120, 50, 0, 2 * 3.14159);
  cairo_fill(cr);

  cairo_select_font_face(cr, "serif", CAIRO_FONT_SLANT_NORMAL,
                         CAIRO_FONT_WEIGHT_BOLD);
  cairo_set_font_size(cr, 32.0);
  cairo_set_source_rgb(cr, 0.0, 0.0, 1.0);
  cairo_move_to(cr, 10.0, 50.0);
  cairo_show_text(cr, filename);

  cairo_destroy(cr);
  cairo_surface_write_to_png(surface, filename);
  cairo_surface_destroy(surface);
}

int main() {
  for (int i = 0; i < 32; i++) {
    create_frame(i);
  }
}
