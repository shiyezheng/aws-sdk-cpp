﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/alexaforbusiness/model/SearchAddressBooksResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::AlexaForBusiness::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

SearchAddressBooksResult::SearchAddressBooksResult() : 
    m_totalCount(0)
{
}

SearchAddressBooksResult::SearchAddressBooksResult(const Aws::AmazonWebServiceResult<JsonValue>& result) : 
    m_totalCount(0)
{
  *this = result;
}

SearchAddressBooksResult& SearchAddressBooksResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("AddressBooks"))
  {
    Array<JsonView> addressBooksJsonList = jsonValue.GetArray("AddressBooks");
    for(unsigned addressBooksIndex = 0; addressBooksIndex < addressBooksJsonList.GetLength(); ++addressBooksIndex)
    {
      m_addressBooks.push_back(addressBooksJsonList[addressBooksIndex].AsObject());
    }
  }

  if(jsonValue.ValueExists("NextToken"))
  {
    m_nextToken = jsonValue.GetString("NextToken");

  }

  if(jsonValue.ValueExists("TotalCount"))
  {
    m_totalCount = jsonValue.GetInteger("TotalCount");

  }



  return *this;
}
