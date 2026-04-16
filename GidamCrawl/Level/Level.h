#pragma once

namespace Gidam
{
	// 모든 게임 레벨의 기반 클래스
	// 게임에 배치되는 액터를 관리
	// 액터에 프레임 이벤트를 전달하는 기능
	// 액터에 필요한 부가 기능 제공
	class Level
	{
	public:
		Level();
		virtual ~Level();
	};
}