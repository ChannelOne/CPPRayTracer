#include <limits>
#include "SceneUnion.h"

bool SceneUnion::intersect(const Ray& ray, IntersectResult& result) const
{
	bool allresult = false;
	float minDistance = std::numeric_limits<float>::max();
	// �������Ҫ��һ��tmp����
	// ��Ϊintersect����Ⱦ��result�����������ֱ�Ӱ�result����ȥ
	// if���ʽǰ��Ϊtrue������Ϊfalse�Ļ�������ͻ᲻��ȷ
	IntersectResult tmpResult;

	for (auto i = begin(); i != end(); ++i)
	{
		auto bResult = (*i)->intersect(ray, tmpResult);
		if (bResult && tmpResult.get_distance() < minDistance)
		{
			allresult = true;
			minDistance = tmpResult.get_distance();
			result = tmpResult;
		}
	}
	return allresult;
}
