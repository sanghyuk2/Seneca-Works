/*************************************************************
****** GAM536NSA , Sanghyuk Lee(129405171) , Assignment 2******
*************************************************************/

Struct Track (
	
	
	col = [135,206,250],
	eCol = [0,291,255],
	
	ang = 0, 
	
	mSeg = 6, 
	mWidth = 30, 
	mLength = 12,
	gap = 0.2, 
	amount = mLength*mSeg + gap*(mSeg-1),
	
	r = (mLength*mSeg+gap*mSeg) * 360/45 * 1/2*1/pi,
	x = r * cos 22.5, 
	offset = (r - x), 
	
	strLen = r/6,
	strAmount = r + gap*(mSeg-1),
	
	gapDiff = strAmount - (strAmount/2 + amount/2), 
	
	
	position_,
	
	start = [0,0,0], 
	position = [0,0,0], 
	heading = [0,1,0],
	headingQuat = quat 0 0 0 1,
	
	
	fn mRight = (
		start = start + offset * heading * quat 90 [0,0,1] 
	),
	
	fn mLeft = (
		start = start + offset * heading * quat -90 [0,0,1]
	),
	
	fn drawStraight = (
		

		--by making an array and put all the objects inside so that I can handle more easier
		board = #()
		position = start
		for i = 1 to mSeg do (
			board[i] = box pos:position length:strLen width:mWidth height:1 wirecolor:col lengthsegs:1
			position = position +  (strLen+gap)*[0,1,0]
		)
		position = start + (strLen+gap)* (mSeg/2-1) * [0,1,0]
		position = position + (strLen+gap)/2 * [0,1,0]
		
		board.pivot = position
		
		board[mSeg+1] = box pos:position length:strAmount width:2 height:3 lengthsegs:mSeg wirecolor:eCol
		board[mSeg+2] = box pos:position length:strAmount width:2 height:3 lengthsegs:mSeg wirecolor:eCol
		
		move board[mSeg+1] [(mWidth/2+1), 0, 0]
		move board[mSeg+2] [-(mWidth/2+1), 0, 0]
		
		board.pivot = position
		
		rotate board (angleaxis ang [0,0,1])
		
		move board [0, -(offset+1.5), 0] 
		
		
		--I could do putting the street lamp in the same way of how I did in the drawLeft/drawRight function
		--but the reason why I did like following is to put the street lamp more on the intersection
		h = position + [0,0,34]
		
		c1 = Cylinder radius:1 pos:position height:30 wirecolor:black
		move c1 [(mWidth/2+1), (mWidth/4), 0]
		g1 = GeoSphere radius:3 pos:h wirecolor:yellow
		move g1 [(mWidth/2+1), (mWidth/4), 0]
		
		c2 = Cylinder radius:1 pos:position height:30 wirecolor:black
		move c2 [(mWidth/2+1), -(mWidth), 0]
		g2 = GeoSphere radius:3 pos:h wirecolor:yellow
		move g2 [(mWidth/2+1), -(mWidth), 0]
		
		c3 = Cylinder radius:1 pos:position height:30 wirecolor:black
		move c3 [-(mWidth/2+1), (mWidth/4), 0]
		g3 = GeoSphere radius:3 pos:h wirecolor:yellow
		move g3 [-(mWidth/2+1), (mWidth/4), 0]
		
		c4 = Cylinder radius:1 pos:position height:30 wirecolor:black
		move c4 [-(mWidth/2+1), -(mWidth), 0]
		g4 = GeoSphere radius:3 pos:h wirecolor:yellow
		move g4 [-(mWidth/2+1), -(mWidth), 0]
		
		start = start + strAmount*heading
	),
	
	fn drawLeft = (
		
		board = #()
		--test = #()
		boxes = #()
		
		position = start
		for i = 1 to mSeg do (
			board[i] = box pos:position length:mLength width:mWidth height:1 wirecolor:col lengthsegs:1
			boxes[i] = box pos: position length: 0 width: 0 height: 0 wirecolor:col 

			position = position +  (mLength+gap)*[0,1,0]
		)
		position = start + (mLength+gap)* (mSeg/2-1) * [0,1,0]
		position = position + (mLength+gap)/2 * [0,1,0] 
		
		board.pivot = position
		
		board[mSeg+1] = box pos:position length:amount width:2 height:3 lengthsegs:mSeg wirecolor:eCol
		board[mSeg+2] = box pos:position length:amount width:2 height:3 lengthsegs:mSeg wirecolor:eCol
		
		move board[mSeg+1] [(mWidth/2+1), 0, 0]
		move board[mSeg+2] [-(mWidth/2+1), 0, 0]
				
		select board 
		
		modPanel.addModToSelection (Bend()) ui:on 
		board[1].modifiers[#bend].bendaxis = 1 
		board[1].modifiers[#bend].bendangle = 45
		board[1].modifiers[#bend].benddir = 180
		
		board.pivot = position
		
		ang = ang + 22.5
		
		rotate board (angleaxis ang [0,0,1])
		
		ang = ang + 22.5
		

			
		h = position + [0,0,34]
		
		boxes.pivot = position
		boxes[mSeg+1] = Cylinder radius:1 pos:position height:30 wirecolor:black
		boxes[mSeg+3] = GeoSphere radius:3 pos:h wirecolor:yellow
		boxes[mSeg+2] = Cylinder radius:1 pos:position height:30 wirecolor:black
		boxes[mSeg+4] = GeoSphere radius:3 pos:h wirecolor:yellow

		move boxes[mSeg+1] [(mWidth/2+1), 0, 0]
		move boxes[mSeg+2] [-(mWidth/2+1), 0, 0]
		
		move boxes[mSeg+3] [(mWidth/2+1), 0, 0]
		move boxes[mSeg+4] [-(mWidth/2+1), 0, 0]
				
		select boxes 
		
		modPanel.addModToSelection (Bend()) ui:on 
		boxes[1].modifiers[#bend].bendaxis = 1 
		boxes[1].modifiers[#bend].bendangle = 45
		boxes[1].modifiers[#bend].benddir = 180
		
		boxes.pivot = position
		
		ang = ang - 22.5
		
		rotate boxes (angleaxis ang [0,0,1])
		
		ang = ang + 22.5
		
		q = quat 45 [0,0,1]
		headingQuat = q * headingQuat
		invQ = inverse q
		heading = heading * invQ
		heading = normalize heading -- good practice to put
		
		start = start + (amount-1.2)*heading
	),
	
	fn drawRight = (
		board = #()
		boxes = #()
		
		
		position = start
		for i = 1 to mSeg do (
			board[i] = box pos:position length:mLength width:mWidth height:1 wirecolor: col lengthsegs:1
			boxes[i] = box pos: position length: 0 width: 0 height: 0 wirecolor:col 

			position = position +  (mLength+gap)*[0,1,0]
		)

		position = start + (mLength+gap)* (mSeg/2-1) * [0,1,0]
		position = position + (mLength+gap)/2 * [0,1,0]
		
		board.pivot = position
		
		board[mSeg+1] = box pos:position length:amount width:2 height:3 lengthsegs:mSeg wirecolor:eCol
		board[mSeg+2] = box pos:position length:amount width:2 height:3 lengthsegs:mSeg wirecolor:eCol
		
		move board[mSeg+1] [(mWidth/2+1), 0, 0]
		move board[mSeg+2] [-(mWidth/2+1), 0, 0]
		
		select board 
		
		modPanel.addModToSelection (Bend()) ui:on 
		
		board[1].modifiers[#bend].bendaxis = 1 
		board[1].modifiers[#bend].bendangle = 45
		board[1].modifiers[#bend].benddir = 360
		
		board.pivot = position
		
		ang = ang - 22.5
		rotate board (angleaxis ang [0,0,1])
		ang = ang - 22.5
			
			
		h = position + [0,0,34]
		
		boxes.pivot = position
		boxes[mSeg+1] = Cylinder radius:1 pos:position height:30 wirecolor:black
		boxes[mSeg+3] = GeoSphere radius:3 pos:h wirecolor:yellow
		boxes[mSeg+2] = Cylinder radius:1 pos:position height:30 wirecolor:black
		boxes[mSeg+4] = GeoSphere radius:3 pos:h wirecolor:yellow

		move boxes[mSeg+1] [(mWidth/2+1), 0, 0]
		move boxes[mSeg+2] [-(mWidth/2+1), 0, 0]
		
		move boxes[mSeg+3] [(mWidth/2+1), 0, 0]
		move boxes[mSeg+4] [-(mWidth/2+1), 0, 0]
				
		select boxes 
		modPanel.addModToSelection (Bend()) ui:on 
		boxes[1].modifiers[#bend].bendaxis = 1 
		boxes[1].modifiers[#bend].bendangle = 45
		boxes[1].modifiers[#bend].benddir = 180
		boxes.pivot = position
		ang = ang + 22.5
		rotate boxes (angleaxis ang [0,0,1])
		ang = ang - 22.5	
			
		
			
		q = quat -45 [0,0,1]
		headingQuat = q * headingQuat
		invQ = inverse q
		heading = heading * invQ
		heading = normalize heading
		
		start = start + (amount-1.2)*heading
	)
)


 fn generatePath PathArray = (
	  delete objects
	 board = Track()
	 boxes = Track()
	 --test = Track()
	 
	for i = 1 to PathArray.count do (
		--Following specifies the cases of order problem
		if i == 1 then (
				if PathArray[1] == "straight" then 
					board.drawStraight()
					
				else if PathArray[i] == "left" then 
					board.drawLeft()
					
				else 
					board.drawRight()
		) else ( 
				if PathArray[i-1] != PathArray[i] do (
					if PathArray[i-1] == "straight" and PathArray[i] == "left" then (
						board.mLeft()
						board.start = board.start + board.gapDiff*board.heading
					) else if PathArray[i-1] == "straight" and PathArray[i] == "right" then(						
						board.mRight()
						board.start = board.start - (board.gapDiff + 0.8)*board.heading
					) else if PathArray[i-1] == "left" and PathArray[i] == "straight" then(
						board.mRight()
						board.start = board.start + (board.gapDiff)*board.heading
					) else if PathArray[i-1] == "left" and PathArray[i] == "right" then (
						board.mRight()
						board.mRight()
					)	else if PathArray[i-1] == "right" and PathArray[i] == "straight" then (
						board.mLeft()
						board.start = board.start + (board.gapDiff-0.5)*board.heading
					) else ( 
						board.mLeft()
						board.mLeft()
					)
				)	 
				
				
				if PathArray[i] == "left" then 
					board.drawLeft()
				else if PathArray[i] == "right" then 
					board.drawRight()
				else
					board.drawStraight()
			
			
		)
	)
 )
 