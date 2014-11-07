#include <stdio.h>
#include "../include/error.h"
#include "../include/defs.h"

/**
 * Prints out the relevant error messages
 *
 * @param errorId
 */
int ErrorMsgs(int errorId, int printFlag) {
    if (printFlag) {
        printf("<ERROR %d>: ", errorId);
        switch (errorId) {
            case RELNOEXIST:
                printf("Relation does not exist! Please check the name and try again.\n");
                break;
            case ATTRNOEXIST:
                printf("Attribute does not exist!\n");
                break;
            case RELNUM_OUT_OF_BOUND:
                printf("Out of bound relation number encountered\n");
                break;
            case NULL_POINTER_EXCEPTION:
                printf("Null pointer exception!\n");
                break;
            case INVALID_ATTR_TYPE:
                printf("Invalid attribute type!\n");
                break;
            case INVALID_COMP_OP:
                printf("Invalid comparison operator!\n");
                break;
            case FILE_SEEK_ERROR:
                printf("Error while seeking!\n");
                break;
            case NULL_ARGUMENT_RECEIVED:
                printf("A NULL argument was received where non-NULL was required!\n");
                break;
            case WRITE_DISK_ERROR:
                printf("Error occurred while writing data to disk!\n");
                break;
            case READ_DISK_ERROR:
                printf("Error occurred while reading data from disk!\n");
                break;
            case NO_ATTRS_FOUND:
                printf("No attributes found for the relation!\n");
                break;
            case NO_CATALOG_FOUND:
                printf("No catalog found in the database!\n");
                break;
            case CAT_FILE_ALREADY_EXIST:
                printf("catalog file(s) already exist in the database!\n");
                break;
            case DB_ALREADY_EXISTS:
                printf("A DB with the given name already exists! \
Please provide a different name and try again\n");
                break;
            case ARGC_INSUFFICIENT:
                printf("Argument(s) missing! The number of arguments received is \
less than required number of arguments!\n");
                break;
            case FILE_SYSTEM_ERROR:
                printf("Error occurred while trying to create file/directory. \
Please check file system permissions and try again.\n");
                break;
            case DBNAME_INVALID:
                printf("Database not found with given name! Please check the database name.\n");
                break;
            case REL_ALREADY_EXISTS:
                printf("A relation with given already exists! Please try again with a different \
name.\n");
                break;
            case INVALID_ATTR_NAME:
                printf("An attribute or relation name is invalid! Names should start with alphabet \
and can be at most 20 characters long.\n");
                break;
            case DB_NOT_OPEN:
                printf("Please call opendb <DBNAME> to open a database first.\n");
                break;
            case DB_NOT_CLOSED:
                printf("Database not closed! Please call CloseDB() before open/create a db \n");
                break;
            case NO_ATTRIBUTES_TO_INSERT:
                printf("Insert has no attribute-value pairs to be inserted into the relation!\n");
                break;
            case ATTR_NOT_IN_REL:
                printf("Attribute with the given name is not found in relation! Please check\
if all attributes are named correctly.\n");
                break;
            case DUPLICATE_TUPLE:
                printf("Tuple already exists in this relation! All tuples must be unique.\n");
                break;
            case METADATA_SECURITY:
                printf("Permission denied! Meta data tables cannot be modified directly.\n");
                break;
            default:
                printf("Unexpected error!\n");
                break;
        }
    }
    return NOTOK;
}
