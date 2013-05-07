/**
 * file tcp-stream.h
 * @brief  TCP Stream
 * @author Pierre-Sylvain Desse
 *
 * The file contains the TCP stream API functions and structures definition
 */

#ifndef _HAKA_PROTO_TCP_STREAM_H
#define _HAKA_PROTO_TCP_STREAM_H

#include <haka/types.h>
#include <haka/stream.h>
#include <haka/tcp.h>


/**
 * Create a new tcp stream.
 * @param start_seq Start TCP sequence number for this stream.
 * @return New allocated TCP stream.
 */
struct stream *tcp_stream_create(size_t start_seq);

/**
 * Push data into a tcp stream.
 * @param stream The tcp stream. This must be a valid tcp stream created with
 * tcp_stream_create().
 * @param tcp Tcp data to push.
 * @return true if successful, false otherwise (see clear_error() to get more
 * details about the error).
 */
bool tcp_stream_push(struct stream *stream, struct tcp *tcp);

/**
 * Pop data from a tcp stream.
 * @param stream The tcp stream. This must be a valid tcp stream created with
 * tcp_stream_create().
 * @return A tcp packet if available. This function will pop all packets that
 * have data before the current position in the stream.
 */
struct tcp *tcp_stream_pop(struct stream *stream);


#endif /* _HAKA_PROTO_TCP_STREAM_H */
