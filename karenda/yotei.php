<!doctype html>
<html class="no-js" lang="">

<head>
  <meta charset="utf-8">
  <title>スケジュール追加</title>
  <meta name="description" content="">
  <meta name="viewport"
	content="width=320,height=480,
		initial-scale=1.0,
		minimum-scale=1.0,
		maximum-scale=2.0,
		user-scalable=yes"/>
  <style type="text/css">
     body{
    background-color:#d1ffff;
    }
  </style>
 
</head>
<body> 
<h1>スケジュール追加</h1>

<?php
$file=$_POST['file'];
$path="/var/www/html/karenda/memo/".$file.".txt";
?>
<form method="post" action="yotei.php">
  <textarea name="comment" cols="50" row="10"></textarea>
  <input type="hidden" name="path" value="<?php echo $path ?>">
  <br>
  <input type="submit" value="追加">
</form>
<br>
<a href="index.php">前のページへ</a>
<br>
<?php
if(isset($_POST['comment'])){
file_put_contents($_POST['path'],$_POST['comment']);
echo "追加しました";
}
?>

</body>
</html>
