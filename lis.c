/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:35:52 by tkok-kea          #+#    #+#             */
/*   Updated: 2023/12/21 15:45:52 by tkok-kea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

/* function to find LIS (Largest Increasing Subsequence)
in stack A so that we dont need to push those numbers to stack B */

int	*create_lis(int *num, int num_size, int *lis_len, int lis_max)
{
	int i;
	int j;
	int *lis;

	lis = (int *)malloc(sizeof(int) * lis_max);
	if (!lis)
		return (NULL);
	return (lis);
}

/* allocates an array same size as num and initialize it with 1s */
int	*lis_len_init(int size)
{
	int *lis_len;
	int i;

	lis_len = (int *)malloc(sizeof(int) * size);
	if (!lis_len)
		return NULL;
	i = 0;
	while (i < size)
	{
		lis_len[i] = 1;
		i++;
	}
	return (lis_len);
}

int	*find_lis(int *num, int num_size, int *lis_max)
{
	int	*lis_len;
	int i;
	int j;

	lis_len = lis_len_init(num_size);
	i = 0;
	while (i < num_size)
	{
		j = i;
		while (j < num_size)
		{
			if (num[j] > num[i] && lis_len[i] == lis_len[j])
			{
				lis_len[j] += 1;
				if (lis_len[j] > *lis_max)
					*lis_max = lis_len[j];
			}
			j++;
		}
		i++;
	}
	return (lis_len);
}

int main(void)
{
	int num[10] = {10, 72, 9, 33, 21, 50, 41, 60, 55, 70};
	int	*lis;
	int lis_size;
	int i;

	lis_size = 0;
	lis = find_lis(num, 10, &lis_size);

	printf("LIS length: %d\n", lis_size);
	i = 0;
	while (i < 10)
		printf("%d ", lis[i++]);

	return (0);
}

int main()
{
int previous_len=0, start=0, c[10], len=0;  //c = final array; will contain the longest consecutive, increasing sequence of numbers
int a[] = {1, 3, 5, 1, 5, 7, 8, 9, 10, 11, 12};
for (int i = 0; i < (sizeof(a)/sizeof(int)); ++i) {
    if(a[i+1] > a[i]) {
        len++;
        if (len > previous_len) { 
            previous_len=len;
            start=i+1-len;
        }
    } else {
        previous_len=len;       
        len=0;
    }
}
for(int i = 0; i <= previous_len; ++i) {
    c[i]=a[start+i]; //here you can copy data to output array, if you need it
    printf("%d ",c[i]); //you can output a[start+i] instead
}
return 0;

}