/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:39:46 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/13 14:31:36 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1000

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd, int *status, char **string);
char	*ft_strchr(const char *s, int c);
char	*ft_strncpy(char *dest, char *src, size_t n);
char	*ft_free(char *s);
char	*add_to_string(char *s, char *buffer, size_t buf_len, int *status);
char	*check_string(char *s, int *status);

#endif
