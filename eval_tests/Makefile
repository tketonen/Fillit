# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jervasti <jonne.ervasti@student.hive.fi>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 09:18:51 by jervasti          #+#    #+#              #
#    Updated: 2022/02/15 13:44:35 by jervasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ALIST = *

ILIST = invalid*

VLIST = valid*
MLIST = map.valid*

all:
	@for map in $(ALIST) ; do \
		echo "\nTesting with file '$$map':" ; \
		valgrind ../fillit $$map ; \
	done

valid:
	@for map in $(VLIST); do \
		echo "\nTesting with file '$$map':" ; \
		../fillit $$map; \
	done

	@for map in $(MLIST); do \
		echo "\nTesting with file '$$map':" ; \
		../fillit $$map; \
	done

vvalid:
	@for map in $(VLIST); do \
		echo "\nTesting with file '$$map':" ; \
		valgrind ../fillit $$map; \
	done

	@for map in $(MLIST); do \
		echo "\nTesting with file '$$map':" ; \
		valgrind ../fillit $$map; \
	done

invalid:
	@for i in $(ILIST); do \
	../fillit $$i; \
	done
