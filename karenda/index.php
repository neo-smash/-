<!doctype html>
<html class="no-js" lang="">

<head>
  <meta charset="utf-8">
  <title>スケジュール帳</title>
    
  <meta name="description" content="">
  <meta name="viewport"
	content="width=320,height=480,
		initial-scale=1.0,
		minimum-scale=1.0,
		maximum-scale=2.0,
		user-scalable=yes"/>
  
  <script type="text/javascript">
    var msg="ポートフォリオ１つ目完成・・・・・・・・・";
    var speed=300;
    var move=2;

    function disp(){
	msg=msg.substring(move,msg.length)+msg.substring(0,move);
	document.form1.field1.value=msg;
	setTimeout("disp()",speed);
    }
    </script>
  
  <style type="text/css">

    body{
    background-color:#d1ffff;
    }
    
    table.calendar_column{
	width:100%;
    }

    table.calendar_column td{
	padding:5px;
	border:1px solid #CCC;
    }

    table.calendar_column tr.week0{
	backgraund-color:#ffefef;
	color:#FF0000;
    }

    table.calendar_column tr.week6{
	background-color:#ededff;
	color:#0000FF;
    }

    table.calendar_column tr.today{
	background-color:#fbffa3;
	font-weight:bold;
    }

    table.calendar_column td:first-child{
	width:20%;
	text-align:center;
    }

    teble.calendar_column td:last-child{
	width:80%;
	color:#111111;	
    }
    
  </style>
 
</head>
<body>
  
  <center>
<h1>MYスケジュール</h1>
  </center>
  
  <br>
  
<center>
<body onLoad="disp()">
  <form action="#" name="form1">
    <input type="text" name="field1" size="30">
  </form>
</body>
</center>

<?php
$path="/var/www/html/karenda/month.txt";
$path2="/var/www/html/karenda/year.txt";

//chmod("month.txt",606);
//chmod("year.txt",606);
//chmod("/memo",606);
//現在の年、月の取得

if(isset($_POST['maina'])){
$month=file_get_contents($path);
$year=file_get_contents($path2);
$month=$month-1;

if($month==0){$month=12;$year=$year-1;}

}

if(isset($_POST['plus'])){
$month=file_get_contents($path);
$year=file_get_contents($path2);
$month=$month+1;

if($month==13){$month=1;$year=$year+1;}

}

if(isset($month)==false and isset($year)==false){
$year=date('Y');
$month=date('n');
}

file_put_contents($path,$month);
file_put_contents($path2,$year);

//echo $month;

//月末日の取得
$end_month=date('j',mktime(0,0,0,$month+1,0,$year));

//echo $end_month;

$arySchedule=[];//スケジュールを入れる


for($i=1;$i<=$end_month;$i++){
$name2="/var/www/html/karenda/memo/".$year.$month.$i.".txt";
$arySchedule[$i]=file_get_contents($name2);
}

$aryCalendar=[];

//1日から月末までをループ
for($i=1;$i<=$end_month;$i++){
$aryCalendar[$i]['day']=$i;
$aryCalendar[$i]['week']=date('w',mktime(0,0,0,$month,$i,$year));

if(isset($arySchedule[$i])){
$aryCalendar[$i]['text']=$arySchedule[$i];
}
else{
$aryCalendar[$i]['text']='';
}
}

$aryWeek=['日','月','火','水','木','金','土'];

?>
	     
<center>
<div style="display:inline-flex">	       
<form method="post" action="index.php">	   
  <input type="hidden" name="maina" value="maina">
  <input type="submit"value="<<">
</form>

<?php echo $year,年,$month,月; ?>
<form method="post" action="index.php">
  <input type="hidden" name="plus" value="plus">
  <input type="submit"value=">>">
</form>
</div>
</center>
<?php $j=1; ?>
<table class="calendar_column">
  <?php foreach($aryCalendar as $value){?>
  <?php if($value['day']!=date('j')){?>
  <tr class="week<?php echo $value['week']?>">
    <?php }
     else if($year==date('Y') and $month==date('n') and 
     $value['day']==date('j')){
     ?>
  <tr class="today">
    <?php } ?>
    <?php $name=$year.$month.$value['day']; ?>
    <td>
<form method="post" action="yotei.php">
  <input type="hidden" name="file" value="<?php echo $name; ?>">
  <input type="submit" value="+">
</form>
    <?php echo $value['day']?>
    (<?php echo $aryWeek[$value['week']]?>)
  </td>
    <td>
      <?php echo $value['text']; ?>
    </td>
  </tr>
  <?php } ?>
</table>

</body>

</html>
