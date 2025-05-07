unlink("a");

// Crear un inodo temporal que se limpie
// cuando se cierre el descriptor
// o finalice el proceso
fd = open("/tmp/xyz", O_CREATE|O_RDWR);
unlink("/tmp/xyz");
