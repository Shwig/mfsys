CFLAGS = -g -std=gnu99
objects = file_sys.o

print_list : $(objects)
	cc -o a $(CFLAGS) $(objects)

.PHONY : clean
clean :
	rm a mf_disk.bin $(objects)
