#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
CFLAGS+=-O2
all: $(NOM)

$(NOM):
	@gcc -c -w $(SRC)
	@ar -r $(NOM) $(SRC)
	@ranlib -no_warning_for_no_symbols $(NOM) 2>/dev/null

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
