/*
    Copyright (C) 2012 Samsung Electronics

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this library; if not, write to the Free Software Foundation,
    Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include "config.h"

#include "UnitTestUtils/EWKTestBase.h"
#include "UnitTestUtils/EWKTestConfig.h"
#include <EWebKit.h>
#include <Ecore.h>
#include <wtf/OwnPtr.h>
#include <wtf/PassOwnPtr.h>

using namespace EWKUnitTests;

/**
* @brief Checking whether function properly returns correct value.
*/
TEST_F(EWKTestBase, ewk_view_editable_get)
{
    loadUrl();
    ewk_view_editable_set(webView(), true);
    ASSERT_TRUE(ewk_view_editable_get(webView()));
}

/**
* @brief Checking whether function returns correct uri string.
*/
TEST_F(EWKTestBase, ewk_view_uri_get)
{
    loadUrl();
    ASSERT_STREQ(Config::defaultTestPage, ewk_view_uri_get(webView()));
}

/**
* @brief Checking whether function properly get/set fullscreen setting value.
*/
TEST_F(EWKTestBase, ewk_view_setting_enable_fullscreen)
{
    loadUrl();
#if ENABLE(FULLSCREEN_API)
    ASSERT_TRUE(ewk_view_setting_enable_fullscreen_get(webView()));

    ASSERT_TRUE(ewk_view_setting_enable_fullscreen_set(webView(), true));
    ASSERT_TRUE(ewk_view_setting_enable_fullscreen_get(webView()));

    ASSERT_TRUE(ewk_view_setting_enable_fullscreen_set(webView(), false));
    ASSERT_FALSE(ewk_view_setting_enable_fullscreen_get(webView()));
#else
    ASSERT_FALSE(ewk_view_setting_enable_fullscreen_get(webView()));

    ASSERT_FALSE(ewk_view_setting_enable_fullscreen_set(webView(), true));
    ASSERT_FALSE(ewk_view_setting_enable_fullscreen_get(webView()));

    ASSERT_FALSE(ewk_view_setting_enable_fullscreen_set(webView(), false));
    ASSERT_FALSE(ewk_view_setting_enable_fullscreen_get(webView()));
#endif
}