item next_produced;

while (true) {
    /* produce an item in next produced */
    while (((in + 1) % BUFFER_SIZE) == out)
    ; /* do nothing */

    buffer[in] = next_produced;
    in = (in + 1) % BUFFER_SIZE;
}


item next_consumed;

while (true) {
    while (in == out)
    ; /* do nothing */
    
    next_consumed = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    /* consume the item in next consumed */
}

message next_produced;
while (true) {
    /* produce an item in next produced */
    
    send(next produced);
}

message next_consumed;
while (true) {
    receive(next consumed);
    
    /* consume the item in next consumed */
}
