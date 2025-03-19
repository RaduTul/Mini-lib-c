// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *aux = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (mem_list_add(aux, size) == -1) {
		munmap(aux, size);
		return NULL;
	}
	if (aux == MAP_FAILED) {
		errno = ENOMEM;
		return NULL;
	}
	return aux;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *aux = malloc(nmemb * size);
	char *p = aux;
    for (size_t i = 0; i < nmemb * size; i++) {
        p[i] = 0;
    }
	if (aux == NULL) {
		errno = ENOMEM;
		return NULL;
	}
	return aux;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr == NULL) {
		exit(-1);
	}
	mem_list_del(ptr);
	munmap(ptr, mem_list_find(ptr)->len);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (size == 0) {
        munmap(ptr, mem_list_find(ptr)->len);
        return NULL;
    }
    if (ptr == NULL) {
        return malloc(size);
    }
    struct mem_list *aux = mem_list_find(ptr);
    if (aux == NULL) {
        return NULL;
    }
    size_t copy_size;
	if (aux->len < size) {
		copy_size = aux->len;
	} else {
		copy_size = size;
	}
    while (size <= aux->len) {
		void *new_ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
		if (new_ptr != ptr) {
			char *p = ptr;
			char *q = new_ptr;
			for (size_t i = 0; i < size && i < aux->len; i++) {
				q[i] = p[i];
			}
			munmap(ptr, aux->len);
			mem_list_del(ptr);
			ptr = new_ptr;
		}
		if (new_ptr == MAP_FAILED) {
			return NULL;
		}
		if (size == aux->len) {
            return ptr;
        }
		aux->len = size;
		return ptr;
    }
    void *new_ptr = malloc(size);
    if (new_ptr == NULL) {
        return NULL;
    }
    char *p = ptr;
	char *q = new_ptr;
	for (size_t i = 0; i < copy_size; i++) {
		q[i] = p[i];
	}
    mem_list_del(ptr);
    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	if (nmemb * size / size != nmemb) {
        errno = ENOMEM;
        return NULL;
    }
    if (nmemb == 0 || size == 0) {
		mem_list_del(ptr);
        munmap(ptr, mem_list_find(ptr)->len);
        return NULL;
    }
    void *new_ptr = realloc(ptr, nmemb * size);
    if (new_ptr == NULL) {
        return NULL;
    }
    return new_ptr;
}