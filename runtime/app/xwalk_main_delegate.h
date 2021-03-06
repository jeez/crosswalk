// Copyright (c) 2013 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CAMEO_RUNTIME_APP_XWALK_MAIN_DELEGATE_H_
#define CAMEO_RUNTIME_APP_XWALK_MAIN_DELEGATE_H_

#include <string>

#include "base/compiler_specific.h"
#include "base/memory/scoped_ptr.h"
#include "cameo/runtime/common/cameo_content_client.h"
#include "content/public/app/content_main_delegate.h"

namespace content {
class ContentBrowserClient;
class ContentRendererClient;
class ContentClient;
}

namespace cameo {

class XWalkMainDelegate : public content::ContentMainDelegate {
 public:
  XWalkMainDelegate();
  virtual ~XWalkMainDelegate();

  // ContentMainDelegate implementation:
  virtual bool BasicStartupComplete(int* exit_code) OVERRIDE;
  virtual void PreSandboxStartup() OVERRIDE;
  virtual int RunProcess(const std::string& process_type,
      const content::MainFunctionParams& main_function_params) OVERRIDE;
  virtual content::ContentBrowserClient* CreateContentBrowserClient() OVERRIDE;
  virtual content::ContentRendererClient*
      CreateContentRendererClient() OVERRIDE;

  static void InitializeResourceBundle();

 private:
  scoped_ptr<content::ContentBrowserClient> browser_client_;
  scoped_ptr<content::ContentRendererClient> renderer_client_;
  scoped_ptr<content::ContentClient> content_client_;

  DISALLOW_COPY_AND_ASSIGN(XWalkMainDelegate);
};

}  // namespace cameo

#endif  // CAMEO_RUNTIME_APP_XWALK_MAIN_DELEGATE_H_
