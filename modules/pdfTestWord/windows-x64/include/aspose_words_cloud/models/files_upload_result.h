﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="files_upload_result.h">
*   Copyright (c) 2022 Aspose.Words for Cloud
* </copyright>
* <summary>
*   Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
* 
*  The above copyright notice and this permission notice shall be included in all
*  copies or substantial portions of the Software.
* 
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*  SOFTWARE.
* </summary> 
-------------------------------------------------------------------------------------------------------------------- **/

#pragma once
#include "./model_base.h"
#include "error.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// File upload result.
    /// </summary>
    class FilesUploadResult : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~FilesUploadResult() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// List of errors.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::Error>> > getErrors() const;

        /// <summary>
        /// List of errors.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setErrors(std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::Error>> > value);


        /// <summary>
        /// List of uploaded file names.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::vector<std::shared_ptr<std::wstring>> > getUploaded() const;

        /// <summary>
        /// List of uploaded file names.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setUploaded(std::shared_ptr< std::vector<std::shared_ptr<std::wstring>> > value);


    protected:
        std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::Error>> > m_Errors;
        std::shared_ptr< std::vector<std::shared_ptr<std::wstring>> > m_Uploaded;
    };
}

