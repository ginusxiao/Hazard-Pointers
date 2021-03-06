/*
  The MIT License (MIT)
  Copyright (c) 2014 Erick Elejalde & Leo Ferres
  (eelejalde|lferres)@udec.cl
  Permission is hereby granted, free of charge, to any person obtaining
  a copy of this software and associated documentation files (the
  "Software"), to deal in the Software without restriction, including
  without limitation the rights to use, copy, modify, merge, publish,
  distribute, sublicense, and/or sell copies of the Software, and to
  permit persons to whom the Software is furnished to do so, subject to
  the following conditions:
  The above copyright notice and this permission notice shall be
  included in all copies or substantial portions of the Software.
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
  Based on:
  http://www.research.ibm.com/people/m/michael/ieeetpds-2004.pdf
*/
#ifndef HZRDPTRS_H_
#define HZRDPTRS_H_

#include "list.h"

 struct hprectype {
  bool active;
  unsigned int rcount; /*retired count*/
  struct listtype *rlist; /*retired list*/
  void *HP[K];
  struct hprectype *next;
};
/* i don't like typedefs, we should change this too... but i'm afraid
   of hp being a very common shorthand */
typedef struct _HP{
  struct hprectype *headHPRec;
  int H;
} HP;

int R(int H) ;
void scan(HP *hp, struct hprectype *myhprec) ;
void help_scan(HP *hp, struct hprectype *myhprec) ;
HP *HP_init() ;
struct hprectype *newHPRec() ;
struct hprectype *allocate_HPRec(HP *hp) ;
void retire_HPRec(struct hprectype *myhprec) ;
void retire_node(HP *hp, struct hprectype *myhprec, void *node) ;

#endif