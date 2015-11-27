/* Teleoperation System for Mobile Manipulators Framework
 *
 * Copyright (C) 2015 
 * RECONFIGURABLE CONTROL OF ROBOTIC SYSTEMS OVER NETWORKS Project
 * Robotics and Control Systems Laboratory
 * Department of Electrical Engineering
 * Sapientia Hungarian University of Transylvania
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * For more details see the project homepage:
 * <http://www.ms.sapientia.ro/~martonl/MartonL_Research_TE.htm>
 */


#ifndef I_VIDEO_CAPTURE_H
#define I_VIDEO_CAPTURE_H

#include <iostream>
#include <string>
#include <boost/shared_array.hpp>

namespace VideoHandler
{
/**
 * The abstract interface for VideoPlayer object.
 * This is used to hide the library dependencies inside the video module.
 */
class IVideoPlayer
{
public:
    /**
     * Pushes an encoded frame for decoding and playback.
     * @param[in] frameStreamId The unique ID of the video stream.
     * @param[in] data The binary data buffer.
     * @param[in] dataLength The length of the data in the buffer.
     */
    virtual void pushEncodedFrame(unsigned int frameStreamId, boost::shared_array<char> data, const unsigned int dataLength) = 0;

    /**
     * Adds a new video playback channel to the player. It has to be called once per video stream before pushing frames into the player.
     * @param[in] frameStreamId The unique ID of the video stream.
     * @param[in] maxDecodingFrameCount The size of the frame queue for the new video stream.
     */
    virtual void addVideoPlayback(unsigned int frameStreamId, unsigned int maxDecodingFrameCount) = 0;
};

/**
 * Specialized smart pointer class.
 */
template <class T>
class IVideoPlayerPtr : public boost::shared_ptr<T>
{
public:
    /**
     * Constructor.
     */
    IVideoPlayerPtr(T* p) : boost::shared_ptr<T>(p) { }
};

/** Type definition for the video player pointer. */
typedef IVideoPlayerPtr<IVideoPlayer> VideoPlayerPtr;  // create an alias for specialized smart pointer

/**
 * Getter for the video player pointer.
 * @return The reference of a video player pointer.
 */
VideoPlayerPtr getVideoPlayer();
} // end namespace VideoHandler

#endif //I_VIDEO_CAPTURE_H
