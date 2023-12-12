/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbihoues <tbihoues@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:19:32 by tbihoues          #+#    #+#             */
/*   Updated: 2023/10/24 19:33:03 by tbihoues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		size;
	char	*dest;

	i = 0;
	size = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * size + 1);
	if (!dest)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int main()
{
    char *original = "Bonjour, comt ça va ?";
    char *copie;

    copie = ft_strdup(original);

    if (copie == NULL)
    {
        printf("Erreur lors de la duplication de la chaîne.\n");
        return 1;
    }

    printf("Chaîne originale : %s\n", original);
    printf("Chaîne dupliquée : %s\n", copie);

    free(copie); // N'oubliez pas de libérer la mémoire allouée dynamiquement.

    return 0;
}
*/