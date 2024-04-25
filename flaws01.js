//javascript 没有overly broad catch的问题，因为catch的error都是同一类型
// function poorErrorHandlingOverlyBroadCatch_Bad01()
// {
//   try {
//     var content=null;
//     console.log(content);
//   } catch (error) {
//     console.error("try catch failed!");
//   }
// }
// function poorErrorHandlingOverlyBroadCatch_Good01()
// {
//   try {
//     var content=null;
//     console.log(content);
//   } catch (error) {
//     console.error("try catch failed!");
//   }
// }

function systemInfoLeakInternal_Bad01()
{
  var http=require('http');
  const options = {
    hostname: 'www.google.com',
    port: 80,
    path: '/upload',
    method: 'POST',
    headers: {
      'Content-Type': 'application/json',
      'Content-Length': Buffer.byteLength(postData),
    },
  };
  http.request(options,function(res){

  }).on('error',function(e){
    //pontential flaw:An internal information leak occurs when system data or debug information is sent to a local file, console, or screen via printing or logging.
    console.log('There was a problem with the request: ' + e);
  });
}

function cmdInjection_Bad01()
{
  var cp = require('child_process');
  var home = process.env('GITPATH');
  var INITCMD="analyzer -s -t";
  var cmd = home + INITCMD;
  child = cp.exec(cmd, function(error, stdout, stderr){
    console.log("Run!");
  });
}

function cmdInjection_Good01()
{
  var cp = require('child_process');
  var INITCMD="analyzer -s -t";
  var cmd = INITCMD;
  child = cp.exec(cmd, function(error, stdout, stderr){
    console.log("Run!");
  });
}
function cmdInjection_Bad02(request,response)
{
  var cp = require('child_process');
  var url=require('url');
  var btype = url.parse(request.url, true)['query']['backuptype'];
  if (btype !== undefined){
    cmd = "c:\\util\\rmanDB.bat" + btype;
    cp.exec(cmd, function(error, stdout, stderr){
      console.log("Run2!");
    });
  }
}
function cmdInjection_Bad03()
{
  require('child_process').exec("make", function(error, stdout, stderr){
    console.log("Run3!");
  });
}

window.onload=function()
{
  cmdInjection_Good01();
  cmdInjection_Bad01();
  var http = require('http');
  http.createServer(cmdInjection_Bad02).listen(8080);
  cmdInjection_Bad03();
}