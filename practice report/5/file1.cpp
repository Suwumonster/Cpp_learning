#define _CRT_SECURE_NO_WARNINGS 1
int factorial(int x)//Çó½×³Ë
{
	if (x == 1)
	{
		return 1;
	}
	else
	{
		return x * factorial(x - 1);
	}
}