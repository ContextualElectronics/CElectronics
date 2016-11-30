# Serial Interface Format
In this document we will go through the format of the serial data as well as provide some examples.

## format
## key
- {START} Start byte = 0xFA
- {END} Start byte   = 0xFB
- {ESCAPE} the escape byte = 0xFC. the next character needs to be inverted ^
- [CHECKSUM] the sum of command, payload_Size and payload
- [] single byte
- .... multiple number of bytes

## structure
```
{START}[command][payload_size_m][payload_size_l][payload_0]......[payload_n][CHECKSUM]{END}
```
## Parser logic
- Reset the parse when ever we receive the {START} byte.
- If we don't receive the {END} byte after we have read all the payload then we discard the current message.
- If receive the {END} byte too early then we discard the current message
- Whenever we receive the {ESCAPE} byte, the next byte will be inverted.
- Discard any messages with invalid checksum
- If Payload_Len is equal to zero then the parser will go start to reading the checksum. this allows for command with zero payload to be received.
- Parser will check if the payload_Len is within the maximun the system can handle.

# Example

*Coded message*
```
0xFA 0x01 0x00 0x02 0xFC 0x03 0xFC 0x02 0xFC 0x01 0xFB
```
*Decoded message*
```
0x01 0x00 0x02 0xFC 0xFB 0xFA
```
*Parser Output*
```
uint8_t Command =  0x01;
uint16_t Length = 0x02;
uint8_t Checksum = 0xFA;
uint8_t Data[] : [0xFC, 0xFB];
```
