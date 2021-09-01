int             main(void)
{
	char *test = malloc(1);
	char *coucou = 0;

	int z = ft_printf("%p, %s, %s, %x, %X, %d, %%\n", test, coucou, "sadasda", -42, 42, 42);
	printf("%d\n", z);
	z = printf("%p, %s, %s, %x, %X, %d, %%\n", test, coucou, "sadasda", -42, 42, 42);
	printf("%d\n", z);
	return 0;
}