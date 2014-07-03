#ifndef WCWIDTH_H
#define WCWIDTH_H 1

#include <wchar.h>

/**
 * wcwidth.h
 *
 * copyright 2014 - mattn <mattn.jp@gmail.com>
 */

int wcwidth(wchar_t);
int wcswidth(const wchar_t*, size_t);
int wcwidth_cjk(wchar_t);
int wcswidth_cjk(const wchar_t*, size_t);
int string_width(const char*);
int string_width_cjk(const char*);

#endif
