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

#include <aws/ec2/model/CapacityReservationSpecificationResponse.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

namespace Aws
{
namespace EC2
{
namespace Model
{

CapacityReservationSpecificationResponse::CapacityReservationSpecificationResponse() : 
    m_capacityReservationPreference(CapacityReservationPreference::NOT_SET),
    m_capacityReservationPreferenceHasBeenSet(false),
    m_capacityReservationTargetHasBeenSet(false)
{
}

CapacityReservationSpecificationResponse::CapacityReservationSpecificationResponse(const XmlNode& xmlNode) : 
    m_capacityReservationPreference(CapacityReservationPreference::NOT_SET),
    m_capacityReservationPreferenceHasBeenSet(false),
    m_capacityReservationTargetHasBeenSet(false)
{
  *this = xmlNode;
}

CapacityReservationSpecificationResponse& CapacityReservationSpecificationResponse::operator =(const XmlNode& xmlNode)
{
  XmlNode resultNode = xmlNode;

  if(!resultNode.IsNull())
  {
    XmlNode capacityReservationPreferenceNode = resultNode.FirstChild("capacityReservationPreference");
    if(!capacityReservationPreferenceNode.IsNull())
    {
      m_capacityReservationPreference = CapacityReservationPreferenceMapper::GetCapacityReservationPreferenceForName(StringUtils::Trim(capacityReservationPreferenceNode.GetText().c_str()).c_str());
      m_capacityReservationPreferenceHasBeenSet = true;
    }
    XmlNode capacityReservationTargetNode = resultNode.FirstChild("capacityReservationTarget");
    if(!capacityReservationTargetNode.IsNull())
    {
      m_capacityReservationTarget = capacityReservationTargetNode;
      m_capacityReservationTargetHasBeenSet = true;
    }
  }

  return *this;
}

void CapacityReservationSpecificationResponse::OutputToStream(Aws::OStream& oStream, const char* location, unsigned index, const char* locationValue) const
{
  if(m_capacityReservationPreferenceHasBeenSet)
  {
      oStream << location << index << locationValue << ".CapacityReservationPreference=" << CapacityReservationPreferenceMapper::GetNameForCapacityReservationPreference(m_capacityReservationPreference) << "&";
  }

  if(m_capacityReservationTargetHasBeenSet)
  {
      Aws::StringStream capacityReservationTargetLocationAndMemberSs;
      capacityReservationTargetLocationAndMemberSs << location << index << locationValue << ".CapacityReservationTarget";
      m_capacityReservationTarget.OutputToStream(oStream, capacityReservationTargetLocationAndMemberSs.str().c_str());
  }

}

void CapacityReservationSpecificationResponse::OutputToStream(Aws::OStream& oStream, const char* location) const
{
  if(m_capacityReservationPreferenceHasBeenSet)
  {
      oStream << location << ".CapacityReservationPreference=" << CapacityReservationPreferenceMapper::GetNameForCapacityReservationPreference(m_capacityReservationPreference) << "&";
  }
  if(m_capacityReservationTargetHasBeenSet)
  {
      Aws::String capacityReservationTargetLocationAndMember(location);
      capacityReservationTargetLocationAndMember += ".CapacityReservationTarget";
      m_capacityReservationTarget.OutputToStream(oStream, capacityReservationTargetLocationAndMember.c_str());
  }
}

} // namespace Model
} // namespace EC2
} // namespace Aws
