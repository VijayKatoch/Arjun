/*
 * http.h
 *
 *  Created on: Dec 31, 2018
 *      Author: Vijay Katoch
 */

#ifndef APP_HTTP_H_
#define APP_HTTP_H_

typedef enum {
                noCmdError = -1,
                turnTurretClk,
                fire,
                turnTurretAntiClk,
                forward,
                reverse,
                leftFwd,
                rightFwd,
                leftRev,
                rightRev,
                stop,
                speed
} POST_COMMAND;

typedef enum {noValError = -1, TRUE,FALSE}COMMAND_BOOL_VAL;



typedef struct
{
    POST_COMMAND    cmd;
    int             value;
}POST_DATA;

typedef struct
{
   /*
    * Not implemented
    */
}PUT_DATA;


#endif /* APP_HTTP_H_ */
