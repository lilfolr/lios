void kmain(void){
    const char *str = "Hello World";
    char *v_mem_ptr = (char )0xb8000;	// Video memory address in protected mode

    unsigned int i = 0;
    unsigned int j = 0;

	// clear screen
	while(j < 80 * 25 * 2) {
		v_mem_ptr[j] = ' ';
		/* attribute-byte - light grey on black screen */
		v_mem_ptr[j+1] = 0x07; 		
		j = j + 2;
	}

	j = 0;
    /* this loop writes the string to video memory */
	while(str[j] != '\0') {
		v_mem_ptr[i] = str[j];
		v_mem_ptr[i+1] = 0x07;
		++j;
		i = i + 2;
	}
	return;
}