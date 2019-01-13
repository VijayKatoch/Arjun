/*
 * httpUtil.c
 *
 *  Created on: Dec 31, 2018
 *      Author: Vijay Katoch
 */

#include <string.h>
#include <stdlib.h>

#include "httpUtil_i.h"

const static struct {
    POST_COMMAND postCmd;
    const char *cmdStr;
} cmdConversion [] = {
        {turnTurretClk, "turnTurretClk"},
        {fire, "fire"},
        {turnTurretAntiClk, "turnTurretAntiClk"},
        {forward, "forward"},
        {reverse, "reverse"},
        {leftFwd, "leftFwd"},
        {rightFwd, "rightFwd"},
        {leftRev, "leftRev"},
        {rightRev, "rightRev"},
        {stop, "stop"},
        {speed, "speed"}
};

const static struct {
    COMMAND_BOOL_VAL cmdBoolVal;
    const char *valStr;
} cmdValueConversion [] = {
        {TRUE, "true"},
        {FALSE, "false"}
};

STATUS getPostFormData(const char* reqData, POST_DATA *data)
{
    STATUS status = ERROR;
    char* cmdStr = strtok(reqData, "=");
    char* valStr = strtok(NULL, "=&");

    POST_COMMAND cmd = getPostReqCommand(cmdStr);
    if(noCmdError == cmd) return (ERR_FORM_DATA);

    int value = getPostCmdValue(valStr);

    data->cmd = cmd;
    data->value = value;

    return OK;
}

POST_COMMAND getPostReqCommand(const char* str)
{
    int i;
    for(i=0; i< sizeof(cmdConversion)/sizeof(cmdConversion[0]); ++i)
        if(!strcmp(str, cmdConversion[i].cmdStr))
            return cmdConversion[i].postCmd;

    return noCmdError;
}

int getPostCmdValue(const char* str)
{
    int i;
    for(i=0; i< sizeof(cmdValueConversion)/sizeof(cmdValueConversion[0]); ++i)
        if(!strcmp(str, cmdValueConversion[i].valStr))
            return (int)cmdValueConversion[i].cmdBoolVal;

    return atoi(str);
}
