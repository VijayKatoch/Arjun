/*
 * app_i.h
 *
 *  Created on: Dec 28, 2018
 *      Author: Vijay Katoch
 */

#ifndef APP_APP_H_
#define APP_APP_H_

#include "http_i.h"

void app_init(void);

void handlePOSTRequest(POST_DATA *data);

#endif /* APP_APP_H_ */
