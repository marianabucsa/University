package rpcprotocol;


public enum RequestType {
    LOGIN, LOGOUT, GET_NR_CHILDREN_ROUND, GET_ALL_ROUNDS,
    FIND_EN_BY_CHILD_ROUND, SAVE_CHILD, GET_CHILDREN_FOR_ROUND,
    GET_CHILD_BY_NAME,GET_CHILDREN_BY_AGEGROUP,SAVE_ENROLLMENT,GET_NR_EN_FOR_CHILD;
}
