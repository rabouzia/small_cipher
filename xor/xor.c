#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int	len;
	
	if (!s1 || !s2)
	return (NULL);
	len = strlen(s1) + strlen(s2) + 1;
	res = (char *)malloc(sizeof(char) * len);
	if (!res)
	return (NULL);
	if (!s1)
	return (strdup(s2));
	if (!s2)
	return (strdup(s1));
	strcpy(res, s1);
	strncat(res, s2, len);
	return (res);
}

char	*strjoin_rest(char const *s1, char const *s2, int rest)
{
	char *res;
	int len_s1, len_total;

	if (!s1 || !s2 || rest <= 0)
		return NULL;

	len_s1 = strlen(s1);
	len_total = len_s1 + (rest < (int)strlen(s2) ? rest : strlen(s2));

	res = malloc(len_total + 1); // +1 for null terminator
	if (!res)
		return NULL;

	strcpy(res, s1);
	strncat(res, s2, rest);  // Only copy `rest` chars from s2

	res[len_total] = '\0';  // Safety null-termination

	return res;
}

char *strjoin_ntime(char *str, int time)
{
	char *res = "";
	while(time > 0)
	{
		res = ft_strjoin(res,str);
		time--;
	}
	return res;
}

int main()
{
	char *mes= "Hello !privet";
	char *key= "xor";
	int i = 0;
	key = strjoin_ntime(key ,strlen(mes) / strlen(key));
	key = strjoin_rest(key, key, strlen(mes) % strlen(key));
	printf("end %s\n", key);
	char *xored = malloc(strlen(mes));
	while(mes[i])
	{
		xored[i] = key[i] ^ mes[i];
		i++;
	}
	printf("xored [%s]\n", xored);
	while(mes[i])
	{
		mes[i] = xored[i] ^ key[i];
		i++;
	}
	printf("unxored [%s]\n", mes);
	

}
