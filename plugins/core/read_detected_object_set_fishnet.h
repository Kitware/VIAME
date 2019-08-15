/*ckwg +29
 * Copyright 2019 by Kitware, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  * Neither name of Kitware, Inc. nor the names of any contributors may be used
 *    to endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * \file
 * \brief Interface for read_detected_object_set_fishnet
 */

#ifndef VIAME_CORE_READ_DETECTED_OBJECT_SET_FISHNET_H
#define VIAME_CORE_READ_DETECTED_OBJECT_SET_FISHNET_H

#include <plugins/core/viame_core_export.h>

#include <vital/algo/detected_object_set_input.h>

#include <memory>

namespace viame {

class VIAME_CORE_EXPORT read_detected_object_set_fishnet
  : public kwiver::vital::algorithm_impl< read_detected_object_set_fishnet,
      kwiver::vital::algo::detected_object_set_input >
{
public:
  static constexpr char const* name = "fishnet";

  // NOTE: Keep description in sync with write_detected_object_set_fishnet
  static constexpr char const* description =
    "Detected object set reader using fishnet csv format.\n\n"
    "  - Column(s) 1: Frame ID no image extension ID\n"
    "  - Column(s) 2: Box ID unique to frame\n"
    "  - Column(s) 3-6: Img-bbox(TL_x,TL_y,BR_x,BR_y)"
    "  - Column(s) 7: Label name\n";

  read_detected_object_set_fishnet();
  virtual ~read_detected_object_set_fishnet();

  virtual void set_configuration( kwiver::vital::config_block_sptr config );
  virtual bool check_configuration( kwiver::vital::config_block_sptr config ) const;

  virtual bool read_set( kwiver::vital::detected_object_set_sptr& set,
                         std::string& image_name );

private:
  virtual void new_stream();

  class priv;
  std::unique_ptr< priv > d;
};

} // end namespace

#endif // VIAME_CORE_READ_DETECTED_OBJECT_SET_FISHNET_H
