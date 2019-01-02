/*
 * main.c
 *
 *  Created on: Dec 28, 2018
 *      Author: Vijay Katoch
 */

#include <string.h>

#include "appweb/appweb.h"
#include "app_i.h"
#include "httpUtil_i.h"

#define HTTP_STR_METHOD_GET             "GET"
#define HTTP_STR_METHOD_POST            "POST"
#define HTTP_STR_METHOD_PUT             "PUT"

/********************************* Code *******************************/
/*
    Run the handler. This is called when all input data has been received.
 */
static void readyRequest(HttpQueue *q)
{
    HttpConn    *conn;

    conn = q->conn;
    httpSetHeaderString(conn, "Custom-Date", conn->http->currentDate);
    httpSetStatus(conn, 200);

    /*
        Generate some dynamic data. If you generate a lot, this will buffer up to a configured maximum.
        If that limit is exceeded, the packet will be sent downstream and the response headers will be created.
     */
    httpWrite(q, "Hello World from PiTank\n");
    /*
        Call finalize when the response to the client is complete. Call httpFlushOutput if the response is
        incomplete and you wish to immediately send any buffered output.
    */
    httpFinalize(conn);
}



static void incomingRequest(HttpQueue *q, HttpPacket *packet)
{

    if (q->conn->error)
    {
        return;
    }
    const char* const HTTP_REQ_METHOD = q->conn->rx->method;

    if (q->conn->rx->length > 0)
    {
        if (strcmp(HTTP_REQ_METHOD, HTTP_STR_METHOD_POST) == 0)
        {
            if (packet->content)
            {
                /*printf("POST Data in packet is %s\n", mprGetBufStart(packet->content));*/
                POST_DATA pData;
                getPostFormData(mprGetBufStart(packet->content), &pData);
                handlePOSTRequest(&pData);
            }
        }
        else if (strcmp(HTTP_REQ_METHOD, HTTP_STR_METHOD_PUT) == 0)
        {
            if (packet->content)
            {
                /*printf("PUT Data in packet is %s\n", mprGetBufStart(packet->content));*/
            }

        }
    }
}


/*
    Module load initialization. This is called when the module is first loaded.
 */
int httpRequestHandlerInit(Http *http, MprModule *module)
{
    HttpStage   *stage;

    if ((stage = httpCreateHandler("requestHandler", module)) == 0) {
        return MPR_ERR_CANT_CREATE;
    }
    stage->ready = readyRequest;
    stage->incoming = incomingRequest;

    /*
     * Application Init
     */
    app_init();

    return 0;
}

