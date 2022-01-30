/*
 * Copyright (c) 2022 Andri Yngvason
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#include "screencopy-interface.h"

struct screencopy* screencopy_create(struct screencopy_impl* impl,
		void* manager, struct wl_output* output, bool render_cursor,
		screencopy_done_fn on_done, void* userdata)
{
	return impl->create(manager, output, render_cursor, on_done, userdata);
}

void screencopy_destroy(struct screencopy* self)
{
	self->impl->destroy(self);
}

int screencopy_start(struct screencopy* self, bool immediate)
{
	return self->impl->start(self, immediate);
}

void screencopy_stop(struct screencopy* self)
{
	self->impl->stop(self);
}
