#include "httpd.h"
#include "http_config.h"
#include "http_core.h"
#include "http_log.h"
#include "http_main.h"
#include "http_protocol.h"
#include "http_request.h"
#include "util_script.h"
#include "http_connection.h"

#include "apr_strings.h"

#include <stdio.h>

static void register_hooks(apr_pool_t *pool);
static int hello_handler(request_rec *r);

module AP_MODULE_DECLARE_DATA hello_module = {
    STANDARD20_MODULE_STUFF, NULL, NULL, NULL, NULL, NULL, register_hooks
};

static void register_hooks(apr_pool_t *pool) {
    ap_hook_handler(hello_handler, NULL, NULL, APR_HOOK_LAST);
}

static int hello_handler(request_rec *r) {
    if (!r->handler || strcmp(r->handler, "hello"))
        return (DECLINED);

    ap_set_content_type(r, "text/plain");
    ap_rputs("Hello, world!", r);
    return OK;
}
