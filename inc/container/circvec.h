#if !defined(CIRCVEC_H)
# define CIRCVEC_H
# include <unistd.h>
# include "types.h"

void circvec_init(circvec *cv, size_t width, size_t size);

void circvec_kill(circvec *cv);

int circvec_full(circvec *cv);

int circvec_empty(circvec *cv);

size_t circvec_get_free(circvec *cv);

size_t circvec_get_used(circvec *cv);

void *circvec_pop(circvec *cv);

void *circvec_peek(circvec *cv);

void *circvec_push(circvec *cv);

void *circvec_get(circvec *cv, ssize_t ind);

#endif