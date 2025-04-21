namespace Rect
{
	inline function reduced(area, amount)
	{
		return [ area[0] + amount, 
				 area[1] + amount, 
				 area[2] - 2 * amount, 
				 area[3] - 2 * amount];
	}
	
	inline function copy(area)
	{
		return [ area[0], area[1], area[2], area[3]];
	}
	
	inline function getCentre(area)
	{
		return [area[0] + area[2]/2, area[1] + area[3]/2];
	}
	
	inline function contains(area, point)
	{
		return point[0] >= area[0] && 
			   point[0] < area[0] + area[2] &&
			   point[1] >= area[1] && 
			   point[1] < area[1] + area[3];
	}
	
	inline function withSizeKeepingCentre(area, width, height)
	{
		return [ area[0] + (area[2] - width) / 2, 
				 area[1] + (area[3] - height) / 2, 
				 width, 
				 height];
	}
	
	inline function removeFromLeft(area, amount)
	{
		area[0] += amount;
		area[2] -= amount;
		return [area[0] - amount, area[1], amount, area[3]];
	}
	
	inline function removeFromRight(area, amount)
	{
		area[2] -= amount;
		return [area[0] + area[2], area[1], amount, area[3]];
	}
	
	inline function removeFromTop(area, amount)
	{
		area[1] += amount;
		area[3] -= amount;
		return [area[0], area[1] - amount, area[2], amount];
	}
	
	inline function scale(area, scaleFactor)
	{
		local newArea = [];
		newArea.reserve(4);
		
		for(a in area)
			newArea.push(a * scaleFactor);
			
		return newArea;
	}
	
	inline function removeFromBottom(area, amount)
	{
		
	

		area[3] -= amount;

		return [area[0], area[1] + area[3], area[2], amount];
	
	}
	
	inline function translated(area, xDelta, yDelta)
	{
		return [area[0] + xDelta, area[1] + yDelta, area[2], area[3]];
	}
	
	inline function withAspectRatioLike(area, otherArea)
	{
		local ar = otherArea[3] / otherArea[2];
		
		local w = area[2];
		local h = area[2] * ar;
		
		local x = area[0];
		local y = area[1] + Math.abs(h - ar[3]) / 2.0;
		
		if(ar > 1.0)
		{
			w = area[3] / ar;
			h = area[3];
			x = area[0] + Math.abs(w - area[2]) / 2.0;
			y = area[1];
		}
		else
		{
			w = area[2];
			h = area[2] * ar;
			x = area[0];
			y = area[1] + Math.abs(h - area[3]) / 2.0;
		}
		
		return [x, y, w, h];
	}
}

inline function withAspectRatioLike2(area, otherArea)
	{
		local ar = otherArea[3] / otherArea[2];
		
		local w = area[2];
		local h = area[2] * ar;
		
		local x = area[0];
		local y = area[1] + Math.abs(h - ar[3]) / 2.0;
		
		if(ar > 1.0)
		{
			w = area[3] / ar;
			h = area[3];
			x = area[0] + Math.abs(w - area[2]) / 2.0;
			y = area[1];
		}
		else
		{
			w = area[2];
			h = area[2] * ar;
			x = area[0];
			y = area[1] + Math.abs(h - area[3]) / 2.0;
		}
		
		return [x, y, w, h];
	}
}