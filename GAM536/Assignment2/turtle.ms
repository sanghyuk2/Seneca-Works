struct Turtle( --struct Turtle 
	--data members
	position_ = [0,0,0], --initially at origin
	heading_ = [0,0,1], --initially pointing up
	rotationQuat_ = quat 0 0 0 1, --identity quaternion, just use it no need to understand how it works
	
	--member functions
	fn forward amount=(
		c=box pos:position_ radius1:20 height:amount
		addmodifier c (bend())
		c.bend.bendangle = 45
		c.bend.bendAxis = 1
		rotate c rotationQuat_
		position_=position_ + amount*heading_
	),
	fn left turnAngle=(
		q = quat -turnAngle [0,1,0] -- creates a quaternion representing a turn of 
												--turnAngle around the y axis
												--it should be unit length, it is called normalize
		
		rotationQuat_ = q * rotationQuat_ -- update the quaternion that represents
														   -- the rotation we need to apply to our object
		
		invq = inverse q						   -- calculate the inverse quaternion to update turtle
		heading_=heading_*invq			   -- use inverse quat to update our heading, just use it
	),
	fn right turnAngle=(
		q = quat turnAngle [0,1,0] 
		
		rotationQuat_ = q * rotationQuat_ 
		
		invq = inverse q						   
		heading_=heading_*invq			   
	)
	
)

fn main = (
	delete objects;
	t = Turtle()

	t.forward 200
	t.right 45
	t.forward 200
	t.right 45
	t.forward 200
	t.right 45
	t.forward 200
	t.right 45
	t.forward 200
	t.right 45
	t.forward 200
	t.right 45
	t.forward 200
	t.right 45
	t.forward 200
	t.right 45

	
)

main()